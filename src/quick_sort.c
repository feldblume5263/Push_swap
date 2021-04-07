/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:53:59 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/07 07:56:01 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				quicksort(int arr[], int start, int end)
{
	int				pivot;
	int				idx;

	pivot = arr[(start + end) / 2];
	idx = start;
	while (end > start && idx <= end)
	{
		if (arr[idx] < pivot)
		{
			swap_arr(arr, idx, start);
			idx++;
		}
		else
		{
			swap_arr(arr, idx, end);
			end--;
		}
	}
	if (end > start)
	{
		quicksort(arr, start, start - 1);
		quicksort(arr, end + 1, end);
	}
}
