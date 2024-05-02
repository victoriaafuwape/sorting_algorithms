#include "sort.h"

/**
 * lomuto_partition - partitions the array using the Lomuto partition scheme for
 * quicksort
 * @array: array of integers to partition
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: total size of the array
 * Return: the partition index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > pivot)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - recursively sorts the array using the quicksort
 * algorithm
 * @array: array of integers to sort
 * @low: lower index of the sub-array to sort
 * @high: higher index of the sub-array to sort
 * @size: total size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 *              Quick sort algorithm with Lomuto partition scheme
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
