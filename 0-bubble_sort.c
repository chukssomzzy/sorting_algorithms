# include "sort.h"

/**
 * bubble_sort - sort an array in assending order
 * @array: array to sort
 * @size: size of array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t j;
	int tmp, swapped = 1;

	if (!array)
		return;

	while (swapped)
	{
		swapped = 0;
		for (j = 0; j < size - 1; j++)
			if (*(array + j) > *(array + j + 1))
			{
				tmp = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = tmp;
				swapped = 1;
				print_array(array, size);
			}
	}
}
