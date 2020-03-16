#include "parser.h"

void	handle_general_state(t_parse_params *p)
{
	p->token = 0;
	if (p->cat == CHAR_WHITE_SPACE || p->cat == CHAR_NEWLINE)
		p->next_state = STATE_GENERAL;
	else if (p->cat == CHAR_SEMICOLON)
		p->next_state = STATE_IN_SEMICOLON;
	else if (p->cat == CHAR_AMPERSAND)
		p->next_state = STATE_IN_AMPERSAND;
	else if (p->cat == CHAR_PIPE)
		p->next_state = STATE_IN_PIPE;
	else if (p->cat == CHAR_SINGLE_QUOTE)
		p->next_state = STATE_IN_SINGLE_QUOTES;
	else if (p->cat == CHAR_DOUBLE_QUOTE)
		p->next_state = STATE_IN_DOUBLE_QUOTES;
	else if (p->cat == CHAR_BACKSLASH)
		p->next_state = STATE_IN_BACKSLASH;
	else if (p->cat == CHAR_GREATER)
		p->next_state = STATE_IN_GREATER;
	else if (p->cat == CHAR_LESS)
		p->next_state = STATE_IN_LESS;
	else if (p->cat == CHAR_GENERAL)
	{
		p->next_state = STATE_IN_STRING;
		p->i--;
	}
	else
	{
		perror("UNIMPLEMENTED");
		exit(1);
	}
}