#include "parser.h"

void	handle_in_single_quotes_state(t_parse_params *p)
{
	if (p->cat == CHAR_NEWLINE)
		p->next_state = STATE_SYNTAX_ERROR;
	else if (p->cat == CHAR_SINGLE_QUOTE)
	{
		p->next_state = STATE_IN_STRING;
	}
	else
	{
		p->next_state = STATE_IN_SINGLE_QUOTES;
		ls_append(&p->token, p->c);
		//TODO: append char to p->token
	}
}
