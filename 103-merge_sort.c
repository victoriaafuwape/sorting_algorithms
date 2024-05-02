#include "sort.h"

/**
 * merge - merges two subarrays of an array in sorted order
 * @array: the array to be sorted
 * @size: the size of the array
 * @mid: the middle index of the array
 * @temp: the temporary array to store the sorted elements
 */
void merge(int *array, size_t size, size_t mid, int *temp)
{
	size_t i = 0, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	while (i < mid && j < size)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < size)
		temp[k++] = array[j++];
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort_recursive - recursively sorts an array using the merge sort
 * @array: the array to be sorted
 * @size: the size of the array
 * @temp: the temporary array to store the sorted elements
 */
void merge_sort_recursive(int *array, size_t size, int *temp)
{
	size_t mid;

	if (size < 2)
		return;
	mid = size / 2;
	merge_sort_recursive(array, mid, temp);
	merge_sort_recursive(array + mid, size - mid, temp);
	merge(array, size, mid, temp);
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 *             Merge sort algorithm (Top-down approach)
 * @array: an array of integers to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	merge_sort_recursive(array, size, temp);
	free(temp);
}
