#include "ft_list.h"
#include <stdlib.h>

int    ft_list_size(t_list *begin_list)
{
	int len;

	len = 1;
	if (!begin_list)
		return (0);
	while (begin_list && begin_list->next != NULL)
	{
		begin_list = begin_list->next;
		len++;
	}
	return (len);
}