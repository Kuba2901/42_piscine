#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *new_struct;
	
	new_struct = (t_list *)malloc(sizeof(t_list));
	new_struct->data = data;
	return (new_struct);
}