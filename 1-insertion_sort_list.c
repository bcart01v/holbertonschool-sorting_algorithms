#include "sort.h"

/**
 * swap_nodes - Function to swap two nodes in a doubly linked list.
 * @node: A pointer to the current node.
 * @list: A pointer to the head of the list.
 */
void swap_nodes(listint_t **node, listint_t **list)
{
	listint_t *current = *node;
	listint_t *next_node, *prev_node;

	if (!(current->prev))
		*list = current->next;

	next_node = current->next;
	current->next = next_node->next;
	prev_node = current->prev;
	current->prev = next_node;
	next_node->next = current;
	next_node->prev = prev_node;

	if (next_node->prev)
		next_node->prev->next = next_node;
	if (current->next)
		current->next->prev = current;

	*node = next_node;
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order.
 * @list: A pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node;

	if (!list || !*list)
		return;

	current_node = *list;

	while (current_node && current_node->next)
	{
		if (current_node->n > current_node->next->n)
		{
			swap_nodes(&current_node, list);
			print_list(*list);

			while (current_node && current_node->prev)
			{
				if (current_node->n < (current_node->prev)->n)
				{
					current_node = current_node->prev;
					swap_nodes(&current_node, list);
					print_list(*list);
					current_node = current_node->next;
				}
				current_node = current_node->prev;
			}
		}
		current_node = current_node->next;
	}
}

