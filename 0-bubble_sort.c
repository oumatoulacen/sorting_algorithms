#include "sort.h"

/**
 * swap - swaps two elements
 * @ele1: first element
 * @ele2: second element
 */
void swap(int *ele1, int *ele2)
{
	int tmp;

	tmp = *ele1;
	*ele1 = *ele2;
	*ele2 = tmp;
}
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				swap(&array[j], &array[j + 1]);
				print_array((const int *)array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}
