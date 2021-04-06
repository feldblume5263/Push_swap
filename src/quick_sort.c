#include <stdio.h>
#include <stdlib.h>

#define MAX			20

void				swap_arr(int arr[], int a_idx, int b_idx)
{
	int				temp;

	temp = arr[a_idx];
	arr[a_idx] = arr[b_idx];
	arr[b_idx] = temp;
}

void				tree_way_quicksort(int arr[], int start, int end)
{
	int				pivot;
	int				idx;
	int				same_s;
	int				same_e;

	same_s = start;
	same_e = end;
	pivot = arr[(start + end) / 2];
	idx = start;
	while (end > start && idx <= same_e)
	{
		if (arr[idx] < pivot)
		{
			swap_arr(arr, idx, same_s);
			same_s++;
			idx++;
		}
		else if (arr[idx] > pivot)
		{
			swap_arr(arr, idx, same_e);
			same_e--;
		}
		else
			idx++;
	}
	if (end > start)
	{
		tree_way_quicksort(arr, start, same_s - 1);
		tree_way_quicksort(arr, same_e + 1, end);
	}
}

int					main(void)
{
	int				arr[MAX] = {3, 9, 2, 3, 43, 3, 5, 9, 2, 20, 4, 45, 48, 54, 23, 64, 41, 43, 24, 49};
	int				idx;

	tree_way_quicksort(arr, 0, MAX - 1);
	idx = 0;
	while (idx < MAX)
	{
		printf("%d ", arr[idx]);
		idx++;
	}
	printf("\n");
}
