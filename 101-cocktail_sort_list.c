#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two nodes of a doubly linked list
 * @list: pointer to the head of the list
 * @node: node to swap
 *
 * Return: void
 */
void swap(listint_t **list, listint_t *node)
{
	listint_t *prev = node->prev, *next = node->next;

	if (prev)
		prev->next = next;
	else
		*list = next;
	next->prev = prev;
	node->prev = next;
	node->next = next->next;
	next->next = node;
	if (node->next)
		node->next->prev = node;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using cocktail shaker sort
 * @list: pointer to pointer to the head of the list
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *node = *list;

	if (node == NULL || node->next == NULL)
		return;
	do {
		swapped = 0;
		while (node->next != NULL){
			if (node->n > node->next->n){
				swap(list, node);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		while (node->prev !=NULL){
			if (node->n < node->prev->n){
				swap(list, node->prev);
				swapped = 1;
			} else {
				node = node->prev;
			}
		}
	}while (swapped);
}

