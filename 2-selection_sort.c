# include "sort.h"

static void swap(int *, int *);
/**
 * selection_sort - divide an array using selection sort
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *tmp;

	for (i = 0; i < size; i++)
	{
		tmp = (array + i);
		for (j = i; j < size; j++)
		{
			if (*(array + j) < *tmp)
				tmp = (array + j);
			if (j == (size - 1) && *tmp != *(array + i))
			{
				swap(tmp, (array + i));
				print_array(array, size);
			}
		}
	}
}

/**
 * swap - swaps two int
 * @fst: first int pointer
 * @sce: second int pointer
 */

void swap(int *fst, int *sce)
{
	int tmp;

	tmp = *fst;
	*fst = *sce;
	*sce = tmp;
}
