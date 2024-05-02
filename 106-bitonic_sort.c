#include "sort.h"

/**
 * swap - Swaps two elements
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * bitonic_merge - Helper function to merge the bitonic sequence
 * @array: Array to sort
 * @low: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @dir: Direction to sort (1 for ascending, 0 for descending)
 * @size: Total size of the main array for printing
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir, size_t size)
{
	size_t k = count / 2, i;

	if (count < 2)
		return;

	for (i = low; i < low + k; i++)
	{
		if (dir == (array[i] > array[i + k]))
		{
			swap(&array[i], &array[i + k]);
			print_array(array, size);
		}
	}
	bitonic_merge(array, low, k, dir, size);
	bitonic_merge(array, low + k, k, dir, size);
}

/**
 * bitonic_sort_recursive - Main recursive function to sort the bitonic
 * sequence
 * @array: Array to sort
 * @low: Starting index of the subarray
 * @count: Number of elements in the subarray
 * @dir: Direction to sort (1 for ascending, 0 for descending)
 * @size: Total size of the main array for printing
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir,
			    size_t size)
{
	size_t k = count / 2;

	if (count < 2)
		return;

	bitonic_sort_recursive(array, low, k, 1, size);

	bitonic_sort_recursive(array, low + k, k, 0, size);

	bitonic_merge(array, low, count, dir, size);
}

/**
 * bitonic_sort - Public function to sort an array using Bitonic sort
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size & (size - 1))
	{
		fprintf(stderr, "Size %lu is not a power of 2\n", size);
		return;
	}
	bitonic_sort_recursive(array, 0, size, 1, size);
}
