#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending
 *            ordrer using the shell sorting algorithm.
 * @array: An array of integrs.
 * @size: The size of an array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 0;
	size_t k, m;
	int tmp;

	if (size < 2)
		return;
	while ((interval = interval * 3 + 1) < size)
		;
	interval =  (interval - 1) / 3;
	for (; interval > 0; interval = (interval - 1) / 3)
	{
		for (k = interval; k < size; k++)
		{
			tmp = array[k];
			for (m = k; m >= interval && tmp <= array[m - interval]; m -= interval)
				array[m] = array[m - interval];
			array[m] = tmp;
		}
		print_array(array, size);
	}
}
