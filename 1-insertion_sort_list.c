#include "sort.h"
/**
 * swap - swaps two nodes in a doubly-linked list.
 * @k: Address of first node.
 * @m: Address of second node.
 *
 * Return: void.
 */
void swap(listint_t *k, listint_t *m)
{
	if (k->prev)
		k->prev->next = m;
	if (m->next)
		m->next->prev = k;
	k->next = m->next;
	m->prev = k->prev;
	k->prev = m;
	m->next = k;
}
/**
 * insertion_sort_list - Insertion sorts a doubly-linked list.
 * @list: Address of pointer to head node.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}
