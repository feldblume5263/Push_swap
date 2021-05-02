/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:48:42 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 19:27:10 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				rotate_a_to_put(t_stack **a, t_stack **b, t_res **res)
{
	int				tag;

	tag = 0;
	tag = is_smallest_size(a, b, res);
	if (tag == 0)
		tag = is_largest_size(a, b, res);
	while (!tag && !(((*a)->index > (*b)->index) &&\
			(stack_last(*a)->index < (*b)->index)))
	{
		if ((*a)->index < (*b)->index)
		{
			ft_rotate(a, b, TAG_A);
			add_operation(res, RA);
		}
		else
		{
			ft_rev_rotate(a, b, TAG_A);
			add_operation(res, RRA);
		}
	}
	ft_push(a, b, TAG_A);
	add_operation(res, PA);
}

int					get_index_order(t_stack *new, int index)
{
	int				count;

	count = 0;
	while (new && new->index != index)
	{
		new = new->next;
		count++;
	}
	count++;
	return (count);
}

int					get_smallest(t_stack *stack)
{
	t_stack			*new;
	int				smallest;

	smallest = stack->index;
	new = stack;
	while (new)
	{
		if (new->index < smallest)
			smallest = new->index;
		new = new->next;
	}
	return (smallest);
}

int					get_largest(t_stack *stack)
{
	t_stack			*new;
	int				largest;

	largest = stack->index;
	new = stack;
	while (new)
	{
		if (new->index > largest)
			largest = new->index;
		new = new->next;
	}
	return (largest);
}
