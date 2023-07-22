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
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	int key, index;
	int i, j, swapped = 0;

	for (i = 0; i < (int)size - 1; i++)
	{
		key = array[i];
		for (j = i + 1; j < (int)size; j++)
		{
			if (key > array[j])
			{
				key = array[j];
				index = j;
				swapped = 1;
			}
		}
		if (swapped)
		{
			swap(&array[i], &array[index]);
			print_array(array, size);
			swapped = 0;
		}
	}
}
