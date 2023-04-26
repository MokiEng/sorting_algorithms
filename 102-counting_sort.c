#include "sort.h"

/**
 * get_max -get the max value in array of integers
 * using the counting sort algorithm
 * @array: an array of integers
 * @size: size of the array
 *
 * Return: the maximum integer in the array
 */

int get_max(int *array, int size)
{
	int max, s;

	for (max = array[0], s = 1; s < size; s++)
	{
		if (array[s] > max)
			max = array[s];
	}

	return (max);
}

/**
 * counting_sort - sort an array of integers in ascending order
 * @array: an array of integers
 * @size: the size of array
 *
 * Description:prints the counting array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, s;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (s = 0; s < (max + 1); s++)
		count[s] = 0;
	for (s = 0; s< (int)size; s++)
		count[array[s]] += 1;
	for (s = 0; s < (max +1);s++)
		count[s] += count[s - 1];
	print_array(count, max + 1);

	for (s = 0; s < (int)size; s++)
	{
		sorted[count[array[s]] - 1] = array[s];
		count[array[s]] -= 1;
	}

	for (s = 0; s < (int)size; s++)
		array[s] = sorted[s];

	free(sorted);
	free(count);
}
