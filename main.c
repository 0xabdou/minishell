#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <get_next_line.h>
#include <libftprintf.h>
#include <utils.h>
#include "parser.h"

void print_tokens(t_list *tokens)
{
	while (tokens)
	{
		char *token = ls_to_string((t_linked_string *)(tokens->content));
		ft_printf("\"%s\" ", token);
		tokens = tokens->next;
	}
	ft_printf("\n");
}

t_char_category translate(char c)
{
	if (c == ';')
		return (CHAR_SEMICOLON);
	if (c == '&')
		return (CHAR_AMPERSAND);
	if (c == '|')
		return (CHAR_PIPE);
	if (c == '\0')
		return (CHAR_NEWLINE);
	if (c == ' ')
		return (CHAR_WHITE_SPACE);
	if (c == '\\')
		return (CHAR_BACKSLASH);
	if (c == '\'')
		return (CHAR_SINGLE_QUOTE);
	if (c == '"')
		return (CHAR_DOUBLE_QUOTE);
	if (c == '$')
		return (CHAR_DOLLAR);
	if (c == '(' || c == ')')
		return (CHAR_INVALID);
	return (CHAR_GENERAL);
}

void minishell_loop()
{
	char			*line;
	int				i;
	int				r;
	int				last_chance;
	t_char_category cat;
	t_state			previous_state;
	t_state			current_state;
	t_state			next_state;
	t_linked_string	*token;
	t_list			*tokens;

	r = 1;
	current_state = STATE_INITIAL;
	while ((r = get_next_line(0, &line)) == 1)
	{
		token = 0;
		tokens = 0;
		last_chance = 1;
		previous_state = STATE_INITIAL;
		current_state = STATE_INITIAL;
		i = 0;
		while (last_chance || line[i])
		{
			cat = translate(line[i]);
			if (!line[i])
			{
				last_chance = 0;
				i--;
			}
			if (current_state == STATE_INITIAL)
			{
				if (cat == CHAR_PIPE || cat == CHAR_AMPERSAND
				|| cat == CHAR_SEMICOLON)
					next_state = STATE_SYNTAX_ERROR;
				else
					next_state = STATE_GENERAL;
				i--;
			}
			else if (current_state == STATE_GENERAL)
			{
				if (token)
					ft_lstadd_back(&tokens, ft_lstnew(token));
				token = 0;
				if (cat == CHAR_WHITE_SPACE || cat == CHAR_NEWLINE)
					next_state = STATE_GENERAL;
				else if (cat == CHAR_SEMICOLON)
					next_state = STATE_IN_SEMICOLON;
				else if (cat == CHAR_AMPERSAND)
					next_state = STATE_IN_AMPERSAND;
				else if (cat == CHAR_PIPE)
					next_state = STATE_IN_PIPE;
				else if (cat == CHAR_SINGLE_QUOTE)
					next_state = STATE_IN_SINGLE_QUOTES;
				else if (cat == CHAR_DOUBLE_QUOTE)
					next_state = STATE_IN_DOUBLE_QUOTES;
				else if (cat == CHAR_GENERAL)
				{
					next_state = STATE_IN_STRING;
					i--;
				}
				else
				{
					perror("UNIMPLEMENTED");
					exit(1);
				}
			}
			else if (current_state == STATE_IN_STRING)
			{
				if (cat == CHAR_GENERAL)
				{
					next_state = STATE_IN_STRING;
					ls_append(&token, line[i]);
					//TODO : append char to token
				}
				else if (cat == CHAR_WHITE_SPACE || cat == CHAR_NEWLINE)
				{
					next_state = STATE_GENERAL;
					//TODO: append token to list
				}
				else if (cat == CHAR_SEMICOLON)
				{
					next_state = STATE_IN_SEMICOLON;
					ft_lstadd_back(&tokens, ft_lstnew(token));
					//TODO: append token to list
				}
				else if (cat == CHAR_AMPERSAND)
				{
					next_state = STATE_IN_AMPERSAND;
					ft_lstadd_back(&tokens, ft_lstnew(token));
					//TODO: append token to list
				}
				else if (cat == CHAR_PIPE)
				{
					next_state = STATE_IN_PIPE;
					ft_lstadd_back(&tokens, ft_lstnew(token));
					//TODO: append token to list
				}
				else if (cat == CHAR_BACKSLASH)
				{
					next_state = STATE_IN_BACKSLASH;
				}
			}
			else if (current_state == STATE_IN_SEMICOLON)
			{
				if (cat == CHAR_GENERAL)
				{
					next_state = STATE_IN_STRING;
					ls_append(&token, line[i]);
					//TODO: append char to token
				}
				else if (cat == CHAR_WHITE_SPACE || cat == CHAR_NEWLINE)
					next_state = STATE_GENERAL;
				else
					next_state = STATE_SYNTAX_ERROR;
			}
			else if (current_state == STATE_IN_PIPE)
			{
				if (cat == CHAR_GENERAL)
				{
					next_state = STATE_IN_STRING;
					//TODO: append | to token list
				}
				else if (cat == CHAR_WHITE_SPACE)
				{
					next_state = STATE_GENERAL;
					//TODO: append | to token list
				}
				else if (cat == CHAR_PIPE)
				{
					next_state = STATE_IN_OR;
				}
				else
				{
					next_state = STATE_SYNTAX_ERROR;
				}
			}
			else if (current_state == STATE_IN_AMPERSAND)
			{
				if (cat == CHAR_AMPERSAND)
				{
					next_state = STATE_IN_AMPERSAND;
				}
				else
				{
					next_state = STATE_SYNTAX_ERROR;
				}
			}
			else if (current_state == STATE_IN_OR)
			{
				if (cat == CHAR_GENERAL)
				{
					next_state = STATE_IN_STRING;
					//TODO: append || to token list
				}
				else if (cat == CHAR_WHITE_SPACE)
				{
					next_state = STATE_GENERAL;
					//TODO: append || to token list
				}
				else
				{
					next_state = STATE_SYNTAX_ERROR;
				}
			}
			else if (current_state == STATE_IN_AND)
			{
				if (cat == CHAR_GENERAL)
				{
					next_state = STATE_IN_STRING;
					//TODO: append && to token list
				}
				else if (cat == CHAR_WHITE_SPACE)
				{
					next_state = STATE_GENERAL;
					//TODO: append && to token list
				}
				else
				{
					next_state = STATE_SYNTAX_ERROR;
				}
			}
			else if (current_state == STATE_IN_SINGLE_QUOTES)
			{
				if (cat == CHAR_SINGLE_QUOTE)
				{
					next_state = STATE_IN_STRING;
				}
				else
				{
					next_state = STATE_IN_SINGLE_QUOTES;
					ls_append(&token, line[i]);
					//TODO: append char to token
				}
			}
			else if (current_state == STATE_IN_DOUBLE_QUOTES)
			{
				if (cat == CHAR_DOUBLE_QUOTE)
				{
					next_state = STATE_IN_STRING;
				}
				else if (cat == CHAR_BACKSLASH)
					next_state = STATE_IN_BACKSLASH;
				else
				{
					next_state = STATE_IN_DOUBLE_QUOTES;
					ls_append(&token, line[i]);
					//TODO: append char to token
				}
			}
			else if (current_state == STATE_IN_BACKSLASH)
			{
				if (cat == CHAR_NEWLINE)
					next_state = STATE_SYNTAX_ERROR;
				else if (previous_state == STATE_IN_DOUBLE_QUOTES)
				{
					if (cat == CHAR_BACKSLASH || cat == CHAR_DOUBLE_QUOTE
						|| cat == CHAR_DOLLAR)
					{
						ls_append(&token, line[i]);
						//TODO: append char to token
					}
					else
					{
						ls_append(&token, '\\');
						ls_append(&token, line[i]);
						//TODO: append backslash and char to token
					}
					next_state = STATE_IN_DOUBLE_QUOTES;
				}
				else if (previous_state == STATE_GENERAL
						 || previous_state == STATE_IN_STRING)
				{
					//TODO: append char to token
					next_state = STATE_IN_STRING;
					ls_append(&token, line[i]);
				}
				else
				{
					perror("current==STATE_IN_BACKSLASH && previous==RETARDED");
					exit(0);
				}
			}
			previous_state = current_state;
			current_state = next_state;
			i++;
		}
		if (current_state == STATE_SYNTAX_ERROR)
		{
			perror("SYNTAX ERROR");
			exit(1);
		}
		print_tokens(tokens);
	}

}

int main() {
	minishell_loop();
	return 0;
}
