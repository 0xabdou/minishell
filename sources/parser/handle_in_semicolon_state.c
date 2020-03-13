#include "parser.h"

void	handle_in_semicolon_state(t_parse_params *p)
{
	if (p->cat == CHAR_GENERAL)
	{
		p->next_state = STATE_IN_STRING;
		ls_append(&p->token, p->c);
		//TODO: append char to p->token
	}
	else if (p->cat == CHAR_WHITE_SPACE || p->cat == CHAR_NEWLINE)
		p->next_state = STATE_GENERAL;
	else
		p->next_state = STATE_SYNTAX_ERROR;
}
