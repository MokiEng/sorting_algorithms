#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - Lomuto partition scheme.
 * @array: array of integers
 * @low: first index
 * @high: last index
 * @size: size of the array
 * Return: index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, tmp;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                print_array(array, size);
            }
        }
    }

    if (i + 1 != high)
    {
        tmp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = tmp;
        print_array(array, size);
    }

    return i + 1;
}

/**
 * quicksort - quick sort algorithm
 * @array: array of integers
 * @low: first index
 * @high: last index
 * @size: size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    int p;

    if (low < high)
    {
        p = lomuto_partition(array, low, high, size);
        quicksort(array, low, p - 1, size);
        quicksort(array, p + 1, high, size);
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
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}

