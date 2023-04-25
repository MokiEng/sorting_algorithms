#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
    int *count_array = NULL;
    int *new_array = NULL;
    int max_value = 0;
    size_t i, j;

    if (!array || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* Allocate memory for count_array */
    count_array = malloc(sizeof(int) * (max_value + 1));
    if (!count_array)
        return;

    /* Initialize all elements of count_array to 0 */
    for (i = 0; i <= max_value; i++)
        count_array[i] = 0;

    /* Count the number of occurrences of each value in array */
    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Print the count_array */
    printf("%d", count_array[0]);
    for (i = 1; i <= max_value; i++)
        printf(", %d", count_array[i]);
    printf("\n");

    /* Allocate memory for new_array */
    new_array = malloc(sizeof(int) * size);
    if (!new_array)
    {
        free(count_array);
        return;
    }

    /* Copy elements from array to new_array in sorted order */
    for (i = 0, j = 0; i <= max_value && j < size; i++)
    {
        while (count_array[i]-- > 0)
            new_array[j++] = i;
    }

    /* Copy elements from new_array back to array */
    for (i = 0; i < size; i++)
        array[i] = new_array[i];

    /* Free allocated memory */
    free(count_array);
    free(new_array);
}

