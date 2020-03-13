#include "utils.h"

size_t	ls_length(const t_linked_string *ls)
{
	size_t	len;

	len = 0;
	while (ls)
	{
		len++;
		ls = ls->next;
	}
	return (len);
}
