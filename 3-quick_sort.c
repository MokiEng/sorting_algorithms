#include "sort.h"

void swap(int *array, size_t size, int *a, int *b);
size_t lomuto_partition(int *array, size_t size,  ssize_t low, size_t high);
void quicksort(int *array, size_t size, ssize_t low, ssize_t high);
void quick_sort(int *array, size_t size);

/**
 * swap - swaps 2 int values
 * @array: the integer array to sort
 * @size: the size of the array
 * @a: address of first value
 * @b: address of second value
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - lomuto partition scheme
 * @array: array of integers
 * @low: first index
 * @high: last index
 * @size: size of the array
 * Return: index of the pivot element
 */

size_t lomuto_partition(int *array, size_t size,  ssize_t low, size_t high)
{
	int pivot = array[high];
	int i, j;

	for (i = j = low; j < high; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[high]);

	return (i);
}

/**
 * quicksort - quick sort algorithm
 * @array: array of integers
 * @low:first index
 * @high: last index
 * @size: size of the array
 */

void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t p = lomuto_partition(array, size, low, high);
		quicksort(array, size, low, p - 1);
		quicksort(array, size, p + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quicksort(array, 0, size - 1, size);
}
