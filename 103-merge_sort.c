#include "sort.h"

void merge_sort(int *array, size_t size);
void merge_recursion(int *buff, int *array, size_t left, size_t right);
void merge_subarray(int *arr, int *array, size_t left,
		    size_t middle, size_t right);
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

	merge_recursion(buff, array, 0, size);
	free(buff);
}

/**
 * merge_recursion - Implement the merge sort algorithm through recursion.
 * @buff: A buffer to store the sorted result.
 * @array: Array to merge sort
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_recursion(int *buff, int *array, size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = (back - front) / 2 + front;
		merge_recursion(buff, array, front, middle);
		merge_recursion(buff, array, middle, back);
		merge_subarray(buff, array, front, middle, back);
	}
}

/**
 * merge_subarray - Merg  a subarray of integers.
 * @buff: Copy array.
 * @array: Array to merge
 * @front: The front index of the array.
 * @middle: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarray(int *buff, int *array, size_t front,
		size_t middle, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[front]: ");
	print_array(array + front, middle  - front);
	printf("[back]: ");
	print_array(array + middle, back - middle);

	for (i = front, j = middle; i < middle && j < back; k++)
	{
		if (array[i] < array[j])
			buff[k] = array[i++];
		else
			buff[k] = array[j++];
	}

	while (i < middle)
		buff[k++] = array[i++];
	while (j < back)
		buff[k++] = array[j++];

	for (k = front, i = 0; k < back; k++)
		array[k] = buff[i++];

	printf("[Done]: ");
	print_array(array + front, back - front);
}
