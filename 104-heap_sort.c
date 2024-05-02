#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - moves the root element to its correct position in the heap
 * @array: the array to be sorted
 * @start: the start index of the heap
 * @end: the end index of the heap
 * @size: the size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap_idx;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap_idx = root;
		if (array[swap_idx] < array[child])
			swap_idx = child;
		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;
		if (swap_idx == root)
			return;
		swap(&array[root], &array[swap_idx]);
		print_array(array, size);
		root = swap_idx;
	}
}

/**
 * heapify - creates a max-heap from an unordered array
 * @array: the array to be sorted
 * @size: the size of the array
 */
void heapify(int *array, size_t size)
{
	size_t start = (size - 2) / 2;

	while (start + 1 > 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using the
 *            Heap sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;

	if (!array || size < 2)
		return;

	heapify(array, size);
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
