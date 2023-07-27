#include "sort.h"

/**
 * swap_nodes - swap two nodes
 * @list: a pointer to a list in which nodes are in
 * @curr: previous node where the iteration begans
 * @end: tail node
 */
void swap_nodes(listint_t **list, listint_t **curr, listint_t **end)
{
	listint_t *n_node;

	n_node = (*curr)->next;
	if ((*curr)->prev)
		(*curr)->prev->next = n_node;
	else
		*list = n_node;
	n_node->prev = (*curr)->prev;
	(*curr)->prev = n_node;
	(*curr)->next = n_node->next;
	if (n_node->next)
		n_node->next->prev = (*curr);
	else
		*end = (*curr);
	n_node->next = (*curr);
	(*curr) = n_node;
}

/**
 * swap_back - swap to nodes in reverse maner
 * @list: a pointer to list we wanna sort
 * @end: end node
 * @curr: the node we start iteration from
 */
void swap_back(listint_t **list, listint_t **curr, listint_t **end)
{
	listint_t *p_node;

	p_node = (*curr)->prev;
	if ((*curr)->next)
		(*curr)->next->prev = p_node;
	else
		*end = p_node;
	p_node->next = (*curr)->next;
	if (p_node->prev)
		p_node->prev->next = *curr;
	else
		*list = *curr;
	(*curr)->next = p_node;
	(*curr)->prev = p_node->prev;
	p_node->prev = *curr;

	(*curr) = p_node;
}
/**
 * cocktail_sort_list - sort a list using cocktail shaker sort
 * @list: a pointer to list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *curr, *end = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (end->next)
		end = end->next;
	while (swapped)
	{
		swapped = 0;
		for (curr = *list; curr != end; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, &curr, &end);
				print_list(*list);
				swapped = 1;
			}
		}
		for (curr = curr->prev; curr != *list; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_back(list, &curr, &end);
				print_list(*list);
				swapped = 1;
			}
		}
	}
}
