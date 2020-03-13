#ifndef PARSER_H
#define PARSER_H

#include "utils.h"
#include "libft.h"

typedef enum	e_state
{
	STATE_INITIAL,
	STATE_GENERAL,
	STATE_IN_STRING,
	STATE_IN_SEMICOLON,
	STATE_IN_PIPE,
	STATE_IN_AMPERSAND,
	STATE_IN_OR,
	STATE_IN_AND,
	STATE_IN_SINGLE_QUOTES,
	STATE_IN_DOUBLE_QUOTES,
	STATE_IN_BACKSLASH,
	STATE_SYNTAX_ERROR,
}				t_state;

typedef enum	e_char_category
{
	CHAR_GENERAL,
	CHAR_WHITE_SPACE,
	CHAR_NEWLINE,
	CHAR_SEMICOLON,
	CHAR_AMPERSAND,
	CHAR_PIPE,
	CHAR_BACKSLASH,
	CHAR_SINGLE_QUOTE,
	CHAR_DOUBLE_QUOTE,
	CHAR_DOLLAR,
	CHAR_INVALID,
}				t_char_category;

typedef struct	s_parse_params
{
	t_state			previous_state;
	t_state			current_state;
	t_state			next_state;
	t_linked_string	*token;
	t_list			*tokens;
}				t_parse_params;

void	handle_general_state();

#endif
