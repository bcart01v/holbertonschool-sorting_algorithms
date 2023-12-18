#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order.
 * @array: Array of integers to be sorted.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min_idx] > array[j])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap_integers(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}

/**
 * swap_integers - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
