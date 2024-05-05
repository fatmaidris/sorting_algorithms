#include "sort.h"
/**
 * swap - swap 2 int values
 * @array: the integer array to sort
 * @size: the size of the array
 * @a: adrress of first value
 * @b: adress of second value
 *
 * Return: void
*/
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomute_partition - partition the array
 * @array: the integer array to sort
 * @size: the size of the array
 * @lo: the low index of sort
 * @hi: the high index of sort
 *
 * Return: size_t
*/
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivot = array[hi];

	for (i = j; j < hi; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++])
	swap(array, size, &array[i], &array[hi]);

	return (i);
}

/**
 * quicksort - quicksort via lomuto partitioning scheme
 * @array: the integer array to sort
 * @size: the size of the array
 * @lo: the los index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: void
*/
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = lomuto_paratition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
}

/**
 * quick_sort - calls quicksort
 * @array: the integer array to sort
 * @size: the size of size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
