#include "sort.h"

/**
 * swap_nodes - Swaps two nodes of a doubly linked list
 *
 * @list: Pointer to pointer to the head of the list
 * @node1: Pointer to first node to swap
 * @node2: Pointer to second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *prev1 = node1->prev;
    listint_t *next2 = node2->next;

    if (prev1)
        prev1->next = node2;
    else
        *list = node2;

    node2->prev = prev1;
    node2->next = node1;
    node1->prev = node2;
    node1->next = next2;

    if (next2)
        next2->prev = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm
 *
 * @list: Pointer to pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start = NULL, *end = NULL, *current = NULL;

    if (!list || !*list)
        return;

    while (swapped)
    {
        swapped = 0;
        for (current = start = (*list); current->next != end; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                swapped = 1;
                print_list(*list);
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        end = current;
        for (current = end->prev; current != start; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                swapped = 1;
                print_list(*list);
            }
        }
        start = current->next;
    }
}

