#include "utils.h"

void	ls_append(t_linked_string **ls, char c)
{
	t_linked_string	*new_node;
	t_linked_string	*l;

	l = *ls;
	new_node = malloc(sizeof(t_linked_string));
	if (!new_node)
	{
		//TODO: proper error handling
		perror("MEMORY ERROR");
		exit(1);
	}
	new_node->c = c;
	new_node->next = 0;
	if (!*ls)
	{
		*ls = new_node;
		return ;
	}
	while (l->next)
		l = l->next;
	l->next = new_node;
}