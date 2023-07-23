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
 * lomuto_partition - the Lomuto partition scheme.
 * @array: the sub array or array to sort.
 * @size: The size of the array.
 * @low: first index of the array (subarray).
 * @high: last index of the array (subarray).
 * Return: the index of the pivot.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > array[high])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sort_rec - do the recursion for quick sort
 * @array: the sub array or array to sort
 * @low: first index
 * @high: last index of the array
 * @size: the size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, pivot_index - 1, size);
		quick_sort_rec(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quick_sort_rec(array, 0, (int)size - 1, size);
}
