#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *curr;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		/*traverse forward*/
		for (curr = *list; curr->next != NULL; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, &curr, curr->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;

		/*Traverse backwards */
		swapped = 0;
		for (; curr->prev != NULL; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, &curr, curr->prev);
				print_list(*list);
				swapped = 1;
			}
		}

	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2)
{
	/* Swap next and prev pointers of node1 and node2 */
	listint_t *temp_next = (*node1)->next;
	listint_t *temp_prev = (*node1)->prev;

	/* Check if node1 or node2 is NULL */
	if (*node1 == NULL || node2 == NULL || list == NULL || *list == NULL)
		return;

	/* Update next pointer of node1's previous node */
        if (temp_prev != NULL)
                temp_prev->next = node2;
        else
                *list = node2; /* Update list head if node1 is the head */

	/* Update prev pointer of node1's next node */
	if (temp_next != NULL)
		temp_next->prev = node2;

	(*node1)->next = node2->next;
	(*node1)->prev = node2->prev;

        node2->prev = temp_prev;
	node2->next = temp_next;

	/* Update next and prev pointers of node2's adjacent nodes */
	if (node2->prev != NULL)
		node2->prev->next = *node1;
	if (node2->next != NULL)
		node2->next->prev = *node1;
}
