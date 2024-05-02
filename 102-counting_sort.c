#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 *                Counting sort algorithm
 * @array: an array of integers to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, max = 0;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
