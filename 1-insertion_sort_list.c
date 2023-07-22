#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr)
	{
		while (curr->prev && curr->prev->n > curr->n)
		{
			curr->prev->next = curr->next;
			if (curr->next)
				curr->next->prev = curr->prev;
			curr->next = curr->prev;
			curr->prev  = curr->next->prev;
			curr->next->prev = curr;
			if (curr->prev)
				curr->prev->next = curr;
			else
				*list = curr;
			print_list((const listint_t *)*list);
		}
		curr = curr->next;
	}
}
