#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @left: pointer to the first node
 * @right: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (!left || !right)
		return;

	/* Detach left node */
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	/* Reattach left node */
	left->next = right->next;
	right->prev = left->prev;

	/* Place left node after right */
	right->next = left;
	left->prev = right;

	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *                      using the Cocktail Shaker sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *left, *right;

	if (!list || !*list || !(*list)->next)
		return;
	do {
		swapped = 0;
		left = *list;
		while (left && left->next)
		{
			right = left->next;
			if (left->n > right->n)
			{
				swap_nodes(list, left, right);
				swapped = 1;
			}
			else
			{
				left = right;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		right = left->prev;
		while (right && right->prev)
		{
			left = right->prev;
			if (left->n > right->n)
			{
				swap_nodes(list, left, right);
				swapped = 1;
			}
			else
			{
				right = left;
			}
		}
	} while (swapped);
}
