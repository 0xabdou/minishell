#include "parser.h"

void	handle_in_backslash_state(t_parse_params *p)
{
	if (p->cat == CHAR_NEWLINE)
		p->next_state = STATE_SYNTAX_ERROR;
	else if (p->previous_state == STATE_IN_DOUBLE_QUOTES)
	{
		if (p->cat == CHAR_BACKSLASH || p->cat == CHAR_DOUBLE_QUOTE
			|| p->cat == CHAR_DOLLAR)
		{
			ls_append(&p->token, p->c);
			//TODO: append char to p->token
		}
		else
		{
			ls_append(&p->token, '\\');
			ls_append(&p->token, p->c);
			//TODO: append backslash and char to p->token
		}
		p->next_state = STATE_IN_DOUBLE_QUOTES;
	}
	else if (p->previous_state == STATE_GENERAL
			 || p->previous_state == STATE_IN_STRING)
	{
		//TODO: append char to p->token
		p->next_state = STATE_IN_STRING;
		ls_append(&p->token, p->c);
	}
	else
	{
		perror("current==STATE_IN_BACKSLASH && previous==RETARDED");
		exit(0);
	}
}
