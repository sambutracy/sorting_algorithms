#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*boolean*/
/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
/*task 0*/
void bubble_sort(int *array, size_t size);
void swap_function(int *a, int *b);
/*task 1*/
void swap_nodes(listint_t **header, listint_t **node1, listint_t *node2);
void insertion_sort_list(listint_t **list);
/*task 2*/
void selection_sort(int *array, size_t size);
/*task 3*/
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
/*task 4*/
void shell_sort(int *array, size_t size);
/*task 5*/
void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **list, listint_t *node1, listint_t *node2);
#endif/*SORT_H*/
