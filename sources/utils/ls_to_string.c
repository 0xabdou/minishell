#include "utils.h"

char	*ls_to_string(const t_linked_string *ls)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ls_length(ls);
	str = malloc((len + 1) * sizeof(char *));
	if (!str)
	{
		//TODO: proper error handling
		perror("MEMORY ERROR");
		exit(1);
	}
	i = 0;
	while (ls)
	{
		str[i] = ls->c;
		ls = ls->next;
		i++;
	}
	str[i] = 0;
	return (str);
}