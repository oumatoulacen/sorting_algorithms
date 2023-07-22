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
 * @low: first index of the array (subarray).
 * @high: last index of the array (subarray).
 * @size: the size of the array
 * Return: the index of the pivot.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j = low - 1, i;

	for (i = low; i <= high - 1; i++)
	{
		if (array[i] < pivot)
		{
			j++;
			swap(&array[j], &array[i]);
			print_array((const int *)array, size);
		}
	}
	j++;
	swap(&array[j], &array[high]);
	return (j);
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
