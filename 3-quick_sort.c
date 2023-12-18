#include "sort.h"

/**
 * _swap - Function to swap two positions in an array.
 * @array: An array of integers.
 * @i: Index of the first element to swap.
 * @j: Index of the second element to swap.
 * @size: Size of the array.
 */
void _swap(int *array, int i, int j, size_t size)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * partition - Function to sort a partition of an array.
 * @array: An array of integers.
 * @start: Index of the start of the partition.
 * @end: Index of the end of the partition.
 * @size: Size of the array.
 * Return: Index of the pivot element.
 */
int partition(int *array, int start, int end, size_t size)
{
	int i = start, j, pivot = array[end];

	for (j = start; j <= end; j++)
	{
		if (array[j] < pivot)
		{
			_swap(array, i, j, size);
			i++;
		}
	}
	_swap(array, i, end, size);
	return (i);
}

/**
 * quicksort - Function to perform the Quick sort algorithm on an array.
 * @array: An array of integers.
 * @start: Index of the start of the partition to sort.
 * @end: Index of the end of the partition to sort.
 * @size: Size of the array.
 */
void quicksort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start >= end)
	{
		return;
	}
	pivot = partition(array, start, end, size);
	quicksort(array, start, pivot - 1, size);
	quicksort(array, pivot + 1, end, size);
}

/**
 * quick_sort - Function to sort an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
