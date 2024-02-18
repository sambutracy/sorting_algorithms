#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm (Lomuto partition scheme)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function to perform quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * partition - Partitions the array and returns the pivot index
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: The index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
