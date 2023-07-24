#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * 		the Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;
	size_t interval = 1;

	if (array == NULL || size <= 1)
		return;
	while (interval < size / 3)
		interval = interval * 3 + 1;
	while (interval <= 1)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		interval = (interval - 1) / 3;
	}
}
