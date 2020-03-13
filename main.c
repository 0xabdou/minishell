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
		char *token = tokens->content;
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
	long long		len;
	t_parse_params	p;

	p.current_state = STATE_INITIAL;
	while (get_next_line(0, &line) == 1)
	{
		p.token = 0;
		p.tokens = 0;
		p.last_chance = 1;
		p.previous_state = STATE_INITIAL;
		p.current_state = STATE_INITIAL;
		p.i = 0;
		len = ft_strlen(line);
		len++;
		while (p.i <= len)
		{
			if (p.i == len && p.current_state != STATE_INITIAL)
			{
				p.next_state = STATE_SYNTAX_ERROR;
				break;
			}
			p.cat = translate(line[p.i]);
			p.c = line[p.i];
			if (p.current_state == STATE_INITIAL)
				handle_initial_state(&p);
			else if (p.current_state == STATE_GENERAL)
				handle_general_state(&p);
			else if (p.current_state == STATE_IN_STRING)
				handle_in_string_state(&p);
			else if (p.current_state == STATE_IN_SEMICOLON)
				handle_in_semicolon_state(&p);
			else if (p.current_state == STATE_IN_PIPE)
				handle_in_pipe_state(&p);
			else if (p.current_state == STATE_IN_AMPERSAND)
				handle_in_ampersand_state(&p);
			else if (p.current_state == STATE_IN_OR)
				handle_in_or_state(&p);
			else if (p.current_state == STATE_IN_AND)
				handle_in_and_state(&p);
			else if (p.current_state == STATE_IN_SINGLE_QUOTES)
				handle_in_single_quotes_state(&p);
			else if (p.current_state == STATE_IN_DOUBLE_QUOTES)
				handle_in_double_quotes_state(&p);
			else if (p.current_state == STATE_IN_BACKSLASH)
				handle_in_backslash_state(&p);
			p.previous_state = p.current_state;
			p.current_state = p.next_state;
			p.i++;
		}
		if (p.current_state == STATE_SYNTAX_ERROR)
		{
			perror("SYNTAX ERROR");
			exit(1);
		}
		print_tokens(p.tokens);
	}

}

int main() {
	minishell_loop();
	return 0;
}
