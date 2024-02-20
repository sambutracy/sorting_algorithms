#include "sort.h"

/**
 * swap_node - Swaps the positions of two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *tmp = node1->prev;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	if (node1->next == node2)
	{
		node1->next = node2->next;
		node2->prev = node1->prev;
		node1->prev = node2;
		node2->next = node1;
	}
	else
	{
		node2->next->prev = node1;
		node1->next->prev = node2;
		node1->prev->next = node2;
		node1->prev = node2->prev;
		node2->prev = tmp;
		tmp = node1->next;
		node1->next = node2->next;
		node2->next = tmp;
	}
}

/**
 * cocktail_sort_list - Sort doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *left, *right;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		left = *list;
		while (left->next != NULL)
		{
			right = left->next;
			if (left->n > right->n)
			{
				swap_node(list, left, right);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				left = left->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		right = left;
		while (right->prev != NULL)
		{
			left = right->prev;
			if (right->n < left->n)
			{
				swap_node(list, left, right);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				right = right->prev;
			}
		}
	} while (swapped);
}
