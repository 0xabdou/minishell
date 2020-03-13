#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_linked_string
{
	char					c;
	struct s_linked_string	*next;
}				t_linked_string;

void			ls_append(t_linked_string **ls, char c);
char			*ls_to_string(const t_linked_string *ls);
size_t			ls_length(const t_linked_string *ls);

#endif
