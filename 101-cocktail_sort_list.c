#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 *
 * @list: Pointer to a pointer to the first element of the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *curr, *tmp;
    int swapped = 1;

    if (!list || !(*list) || !(*list)->next)
        return;

    while (swapped)
    {
        swapped = 0;
        for (curr = *list; curr->next != NULL; curr = curr->next)
        {
            if (curr->n > curr->next->n)
            {
                tmp = curr->next;
                curr->next = tmp->next;
                if (tmp->next != NULL)
                    tmp->next->prev = curr;
                tmp->prev = curr->prev;
                if (curr->prev != NULL)
                    curr->prev->next = tmp;
                else
                    *list = tmp;
                curr->prev = tmp;
                tmp->next = curr;
                swapped = 1;
                print_list(*list);
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        for (curr = curr->prev; curr->prev != NULL; curr = curr->prev)
        {
            if (curr->n < curr->prev->n)
            {
                tmp = curr->prev;
                curr->prev = tmp->prev;
                if (tmp->prev != NULL)
                    tmp->prev->next = curr;
                tmp->next = curr->next;
                if (curr->next != NULL)
                    curr->next->prev = tmp;
                else
                    *list = tmp;
                curr->next = tmp;
                tmp->prev = curr;
                swapped = 1;
                print_list(*list);
            }
        }
    }
}

