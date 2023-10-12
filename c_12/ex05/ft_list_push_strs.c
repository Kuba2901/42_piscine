#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *new_struct;
	
	new_struct = (t_list *)malloc(sizeof(t_list));
    if (new_struct)
    {
	    new_struct->data = data;
        new_struct->next = NULL;
    }
	return (new_struct);
}

 void ft_list_push_front(t_list **begin_list, void *data)
 {
    t_list  *new = ft_create_elem(data);
    if (new)
    {
        new->next = *begin_list;
        *begin_list = new;
    }
 }

 t_list *ft_list_push_strs(int size, char **strs)
 {
    t_list  *list;
    t_list  *temp;
    int     i;    

    list = NULL;
    i = -1;
    while (++i < size)
        ft_list_push_front(&list, strs[i]);
    return (list);
 }