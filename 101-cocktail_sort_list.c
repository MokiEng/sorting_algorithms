#include "sort.h"
/**
 * cocktail_sort_list - sort doubly linked list in ascending order using Cocktail Shaker sort
 * @list: doubly linked list to be sorted
 * Return: no return value (void)
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tmp, *current = *list;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        while (current->next != NULL) {
            if (current->n > current->next->n) {
                /* swap the nodes */
                tmp = current->next;
                current->next = tmp->next;
                if (tmp->next != NULL)
                    tmp->next->prev = current;
                tmp->prev = current->prev;
                if (current->prev != NULL)
                    current->prev->next = tmp;
                else
                    *list = tmp;
                current->prev = tmp;
                tmp->next = current;
                print_list(*list);
            } else
                current = current->next;
        }
        /* end of the list. Move backward */
        current = current->prev;
        while (current->prev != NULL) {
            if (current->n < current->prev->n) {
                /* swap the nodes */
                tmp = current->prev;
                current->prev = tmp->prev;
                if (tmp->prev != NULL)
                    tmp->prev->next = current;
                else
                    *list = current;
                tmp->next = current->next;
                if (current->next != NULL)
                    current->next->prev = tmp;
                current->next = tmp;
                tmp->prev = current;
                print_list(*list);
            } else
                current = current->prev;
        }
    } while (tmp != NULL);
}

