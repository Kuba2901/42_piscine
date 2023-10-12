#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *new_struct;
	
	new_struct = (t_list *)malloc(sizeof(t_list));
	new_struct->data = data;
	return (new_struct);
}

void	ft_list_push_back(t_list **begin_list, void *data) {
	t_list	*head;
	t_list	*new;

	new = ft_create_elem(data);
	if (!new)
		return ;
	new->next = NULL;
	head = *begin_list;
	if (head == NULL)
		*begin_list = new;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}	
}