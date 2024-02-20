#include "sort.h"

/**
 * heapify - Function to heapify a subtree rooted at index 'i'
 * @array: The input array
 * @size: The size of the heap
 * @i: The index of the root of the subtree
 */
void heapify(int *array, size_t size, int i, size_t len)
{
    int largest = i;    /* Initialize largest as root */
    int left = 2 * i + 1;    /* left = 2*i + 1 */
    int right = 2 * i + 2;    /* right = 2*i + 2 */
    int temp = array[i];

    /* If left child is larger than root */
    if (left < (int)size && array[left] > array[largest])
        largest = left;

    /* If right child is larger than largest so far */
    if (right < (int)size && array[right] > array[largest])
        largest = right;

    /* If largest is not root */
    if (largest != i)
    {
        /* Swap the root and largest */
        array[i] = array[largest];
        array[largest] = temp;
	print_array(array, len);
	heapify(array, size, largest, len);
    }
}

/**
 * heap_sort - Function to sort an array of integers in ascending order
 * using the Heap Sort algorithm
 * @array: The input array
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;
    int temp = array[0];

    if(!array || size < 2)
	    return;

    /* Build heap (rearrange array) */
    for (i = (size / 2) - 1; i >= 0; i--)
        heapify(array, size, i, size);

    /* One by one extract an element from heap */
    for (i = size - 1; i > 0; i--)
    {
        /* Move current root to end */
        array[0] = array[i];
        array[i] = temp;
	print_array(array, size);
	heapify(array, i, 0, size);
    }
}
