#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

// Function to free a simple integer (for demonstration)
void free_int(void *data) {
    int *ptr = (int *)data;
    free(ptr);
}

int main() {
    // Create a sample linked list
    t_list *list = NULL;

    // Test data
    int *data1 = (int *)malloc(sizeof(int));
    int *data2 = (int *)malloc(sizeof(int));
    int *data3 = (int *)malloc(sizeof(int));

    *data1 = 10;
    *data2 = 20;
    *data3 = 30;

    // Add elements to the list
    ft_list_push_back(&list, data1);
    ft_list_push_back(&list, data2);
    ft_list_push_back(&list, data3);

    // Print the list before clearing
    printf("Linked List Before Clearing: ");
    t_list *current = list;
    while (current != NULL) {
        printf("%d -> ", *(int *)current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Clear the list and free the data
    ft_list_clear(list, free_int);
    list = NULL;

    // Print the list after clearing
    printf("Linked List After Clearing: ");
    current = list;  // Should be NULL
    while (current != NULL) {
        printf("%d -> ", *(int *)current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
