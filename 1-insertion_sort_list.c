#include "sort.h"

/**
 * swap_nodes - swap two nodes of a double linked list
 * @f_node: first node
 * @s_node: second node
 * @node: the head of the list
 */

void swap_nodes(listint_t **node, listint_t **f_node, listint_t **s_node)
{
	listint_t *f_prev = (*f_node)->prev;
	listint_t *s_next = (*s_node)->next;

	(*f_node)->next = s_next;
	if ((*s_node)->next)
		(*s_node)->next->prev = *f_node;
	(*f_node)->prev = *s_node;
	(*s_node)->prev = f_prev;
	(*s_node)->next = *f_node;

	if ((*f_node)->prev)
		(*f_node)->prev->next = (*s_node);
	else
		*node = (*s_node);
}


/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr;

	if (!(list || (*list)->next || *list))
		return;

	curr = (*list)->next;
	while (curr)
	{
		while (curr->prev && curr->prev->n > curr->n)
		{
			swap_nodes(list, &curr->prev, &curr);
			print_list((const listint_t *)*list);
		}
		curr = curr->next;
	}
}
