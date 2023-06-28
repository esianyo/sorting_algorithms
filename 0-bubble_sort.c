#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using bubble sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, count;
	int tmp;

	if (size < 2)
		return;

	for (count = 0; size - 1 != count;)
	{
		for (i = 0; i + 1 != size; i++)
		{
			if (array[i + 1] < array[i])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
			else
				count++;
		}
	}
}
