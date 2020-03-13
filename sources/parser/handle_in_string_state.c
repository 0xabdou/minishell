#include "parser.h"

void	handle_in_string_state(t_parse_params *p) {
	if (p->cat == CHAR_GENERAL) {
		p->next_state = STATE_IN_STRING;
		ls_append(&p->token, p->c);
		//TODO : append char to p->token
	} else if (p->cat == CHAR_WHITE_SPACE) {
		p->next_state = STATE_GENERAL;
		ft_lstadd_back(&p->tokens, ft_lstnew(p->token));
		//TODO: append p->token to list
	}
	else if (p->cat == CHAR_NEWLINE)
	{
		p->next_state = STATE_INITIAL;
		ft_lstadd_back(&p->tokens, ft_lstnew(p->token));
		//TODO: append p->token to list
	}
	else if (p->cat == CHAR_SEMICOLON)
	{
		p->next_state = STATE_IN_SEMICOLON;
		ft_lstadd_back(&p->tokens, ft_lstnew(p->token));
		//TODO: append p->token to list
	}
	else if (p->cat == CHAR_AMPERSAND)
	{
		p->next_state = STATE_IN_AMPERSAND;
		ft_lstadd_back(&p->tokens, ft_lstnew(p->token));
		//TODO: append p->token to list
	}
	else if (p->cat == CHAR_PIPE)
	{
		p->next_state = STATE_IN_PIPE;
		ft_lstadd_back(&p->tokens, ft_lstnew(p->token));
		//TODO: append p->token to list
	}
	else if (p->cat == CHAR_BACKSLASH)
	{
		p->next_state = STATE_IN_BACKSLASH;
	}
	else if (p->cat == CHAR_DOUBLE_QUOTE)
		p->next_state = STATE_IN_DOUBLE_QUOTES;
	else if (p->cat == CHAR_SINGLE_QUOTE)
		p->next_state = STATE_IN_SINGLE_QUOTES;
}
