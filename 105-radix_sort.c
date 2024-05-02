#include "sort.h"

/**
 * count_sort - counting sort of an array according to the digit represented
 *              by exponent
 * @array: the array to be sorted
 * @size: the size of the array
 * @exp: the exponent of the digit to be sorted (by 1s, 10s, 100s, etc)
 * @output: the output array
 */
void count_sort(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i + 1 > 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - sorts an array of integers in ascending order using the
 *             LSD Radix sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *output;
	int max, exp;
	size_t i;

	if (!array || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
