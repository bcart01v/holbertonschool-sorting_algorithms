#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
{
	for (size_t j = 0; j < size - i - 1; j++)
	{
	if (array[j] > array[j + 1])
		{
		int temp = array[j];
		array[j] = array[j + 1];
		array[j + 1] = temp;
	  }
	}
	
	for (size_t k = 0; k < size; k++)
	{
	  printf("%d ", array[k]);
	}
	printf("\n");
  }
}

int my_main(void)
{
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  size_t size = sizeof(array) / sizeof(array[0]);
  bubble_sort(array, size);
  return 0;
}
