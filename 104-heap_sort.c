#include "sort.h"

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t s, size_t root, size_t size);

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int k, temp;

	if (size < 2)
		return;
	for (k = size / 2 - 1; k >= 0; k--)
		heapify(array, size, (size_t)k, size);
	for (k = size - 1; k >= 0; k--)
	{
		temp = array[k];
		array[k] = array[0];
		array[0] = temp;
		if (k != 0)
			print_array(array, size);
		heapify(array, (size_t)k, 0, size);
	}
}

/**
 * heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @s: The size of the subtree.
 * @root: The root node of the binary tree in the heap.
 * @size: Size of the whole array.
 */
void heapify(int *array, size_t s, size_t root, size_t size)
{
	size_t large, left, right;
	int temp;

	large = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;

	if (left < s && array[left] > array[large])
		large = left;

	if (right < s && array[right] > array[large])
		large = right;

	if (large != root)
	{
		temp = array[root];
		array[root] = array[large];
		array[large] = temp;
		print_array(array, size);
		heapify(array, s, large, size);
	}
}
