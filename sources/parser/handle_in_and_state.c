#include "parser.h"

void	handle_in_and_state(t_parse_params *p)
{
	if (p->cat == CHAR_GENERAL)
	{
		p->next_state = STATE_IN_STRING;
		append_token_str(&p->tokens, ft_strdup("&&"));
		//TODO: append && to p->token list
	}
	else if (p->cat == CHAR_WHITE_SPACE)
	{
		p->next_state = STATE_GENERAL;
		append_token_str(&p->tokens, ft_strdup("&&"));
		//TODO: append && to p->token list
	}
	else
	{
		p->next_state = STATE_SYNTAX_ERROR;
	}
}
