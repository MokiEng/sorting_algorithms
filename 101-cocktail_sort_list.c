#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: Double pointer to the first element of the doubly linked list
 *
 * Return: Void
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *temp, *current;
    int swapped = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped == 1)
    {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                temp = current->next;
                current->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = current;
                temp->prev = current->prev;
                if (current->prev != NULL)
                    current->prev->next = temp;
                else
                    *list = temp;
                current->prev = temp;
                temp->next = current;
                swapped = 1;
                print_list(*list);
            }
        }
        if (swapped == 0)
            break;
        swapped = 0;
        for (current = current->prev; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                temp = current->prev;
                current->prev = temp->prev;
                if (temp->prev != NULL)
                    temp->prev->next = current;
                else
                    *list = current;
                temp->next = current->next;
                if (current->next != NULL)
                    current->next->prev = temp;
                current->next = temp;
                temp->prev = current;
                swapped = 1;
                print_list(*list);
            }
        }
    }
}

