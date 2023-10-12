#include "ft_list.h"
#include <stdlib.h>

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *)) {
    t_list *current = begin_list;
    t_list *temp;

    while (current) {
        temp = current;
        current = current->next;
        if (free_fct)
            free_fct(temp->data);
        free(temp);
    }
}
