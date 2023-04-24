#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - Lomuto partition scheme.
 * @array: array of integers
 * @low: first index
 * @high: last index
 * @size: size of the array
 * Return: index of pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, tmp;

    for (j = low; j <= high - 1; j++)
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
    if (array[i + 1] > array[high])
    {
        tmp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = tmp;
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quick_sort_helper - Helper function to implement the quick sort algorithm.
 * @array: array of integers
 * @low: first index
 * @high: last index
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
    int pivot_index;

    if (low < high)
    {
        pivot_index = lomuto_partition(array, low, high, size);
        quick_sort_helper(array, low, pivot_index - 1, size);
        quick_sort_helper(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 * sort algorithm with Lomuto partition scheme.
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
}

