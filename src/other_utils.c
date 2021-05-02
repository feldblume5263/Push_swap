/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:53:51 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 18:27:11 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					get_gap(int a, int b)
{
	int				ret;

	ret = a - b;
	if (ret < 0)
		ret *= -1;
	return (ret);
}

int					is_largest_size(t_stack **a, t_stack **b, t_res **res)
{
	t_stack			*new;
	int				compare;

	new = *a;
	compare = (*b)->index;
	while (new)
	{
		if (compare < new->index)
			return (0);
		new = new->next;
	}
	move_smallest_to_first(a, res);
	return (1);
}

int					is_smallest_size(t_stack **a, t_stack **b, t_res **res)
{
	t_stack			*new;
	int				compare;

	new = *a;
	compare = (*b)->index;
	while (new)
	{
		if (compare > new->index)
			return (0);
		new = new->next;
	}
	move_smallest_to_first(a, res);
	return (1);
}

void				swap_arr(int arr[], int a_idx, int b_idx)
{
	int				temp;

	temp = arr[a_idx];
	arr[a_idx] = arr[b_idx];
	arr[b_idx] = temp;
}
