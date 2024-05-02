#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: a pointer to the head of the doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			prev = current->prev;
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;
			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;
			print_list(*list);
		}
		current = next;
	}
}
