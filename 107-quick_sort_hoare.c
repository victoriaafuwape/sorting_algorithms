#include "sort.h"
#include <stdio.h>

/**
 * swap_elements - Swaps two elements in an array and prints the array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 * @array: Array to print
 * @size: Size of the array
 */
void swap_elements(int *a, int *b, int *array, size_t size)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * hoare_partition - Lomuto partition scheme for quicksort algorithm
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 * Return: Index of the pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_elements(&array[i], &array[j], array, size);
	}
}

/**
 * quick_sort_recursive - Recursive function for the quicksort algorithm
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = hoare_partition(array, low, high, size);

		quick_sort_recursive(array, low, pi, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 *                    quick sort algorithm with Hoare partition scheme
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
