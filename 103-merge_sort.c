#include "sort.h"

/**
 * sort_subarr - Sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @f_index: The front index of the array.
 * @m_index: The middle index of the array.
 * @back: The back index of the array.
 */
void sort_subarr(int *subarray, int *buff, size_t f_index, size_t m_index,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + f_index, m_index - f_index);

	printf("[right]: ");
	print_array(subarray + m_index, back - m_index);

	for (i = f_index, j = m_index; i < m_index && j < back; k++)
		buff[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < m_index; i++)
		buff[k++] = subarray[i];
	for (; j < back; j++)
		buff[k++] = subarray[j];
	for (i = f_index, k = 0; i < back; i++)
		subarray[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarray + f_index, back - f_index);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @f_index: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarray, int *buff, size_t f_index, size_t back)
{
	size_t mid;

	if (back - f_index > 1)
	{
		mid = f_index + (back - f_index) / 2;
		merge_sort_recursive(subarray, buff, f_index, mid);
		merge_sort_recursive(subarray, buff, mid, back);
		sort_subarr(subarray, buff, f_index, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
