/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:53:59 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 19:35:45 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				init_stack_isa(t_stack *a)
{
	t_stack			*new;

	new = a;
	while (new)
	{
		new->is_a = 0;
		new = new->next;
	}
}

t_stack				*start_with_headmark(int headmark, t_stack *a)
{
	t_stack			*new;

	new = a;
	while (new)
	{
		if (new->index == headmark)
		{
			new->is_a = 1;
			new = new->next;
			break ;
		}
		new = new->next;
	}
	return (new);
}

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
