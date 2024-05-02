#include "sort.h"

/**
 * swap - swaps two integers
 * @a: the first integer
 * @b: the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - merges two subarrays in bitonic order
 * @array: the array to be sorted
 * @low: the starting index of the first subarray
 * @count: the number of elements to be merged
 * @dir: the direction of sorting
 * @size: the size of the array
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir, size_t size)
{
	size_t i, k = count / 2;

	if (count < 2)
		return;

	for (i = low; i < low + k; i++)
	{
		if ((array[i] > array[i + k]) == dir)
			swap(&array[i], &array[i + k]);
	}

	bitonic_merge(array, low, k, dir, size);
	bitonic_merge(array, low + k, k, dir, size);
}

/**
 * bitonic_sort_recursive - recursively sorts a bitonic sequence in ascending
 *                        order
 * @array: the array to be sorted
 * @low: the starting index of the sequence
 * @count: the number of elements in the sequence
 * @dir: the direction of sorting (1 for ascending, 0 for descending)
 * @size: the size of the array
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
 * bitonic_sort - sorts an array of integers in bitonic order
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1, size);
}
