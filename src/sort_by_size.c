/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 17:55:59 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 22:01:37 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				sorting_size(t_stack **a, t_stack **b, t_res **res)
{
	int				mark;

	mark = set_headmark(*a);
	set_size_mark(*a, mark);
	size_a_to_b(a, b, res);
	while (stack_size(*b) != 0)
	{
		size_b_to_a(a, b, res);
	}
	move_smallest_to_first(a, res);
}

void				size_a_to_b(t_stack **a, t_stack **b, t_res **res)
{
	int				mark;

	while ((mark = count_markup(*a)) != stack_size(*a))
	{
		if (size_check_swap_effect(a, b, mark) == 1)
			add_operation(res, SA);
		else if ((*a)->is_a == 0)
		{
			ft_push(a, b, TAG_B);
			add_operation(res, PB);
		}
		else
		{
			ft_rotate(a, b, TAG_A);
			add_operation(res, RA);
		}
	}
}

void				size_b_to_a(t_stack **a, t_stack **b, t_res **res)
{
	int				idx;
	int				operation;

	idx = 0;
	while (idx < 20)
	{
		operation = prepare_move(a, b);
		size_run_operation(a, b, operation);
		add_operation(res, operation);
		idx++;
	}
	rotate_a_to_put(a, b, res);
}

int					size_check_swap_effect(t_stack **a, t_stack **b, int mark)
{
	int				headmark;

	ft_swap(a, b, TAG_A);
	headmark = set_headmark(*a);
	set_size_mark(*a, headmark);
	if (count_markup(*a) <= mark)
	{
		ft_swap(a, b, TAG_A);
		headmark = set_headmark(*a);
		set_size_mark(*a, headmark);
		return (FALSE);
	}
	else
		return (TRUE);
}

#include <stdio.h>
void				set_size_mark(t_stack *a, int headmark)
{
	t_stack			*new;
	int				largest;

	init_stack_isa(a);
	new = start_with_headmark(headmark, a);
	largest = headmark;
	while (new && new->index > largest)
	{
		largest = new->index;
		new->is_a = 1;
		new = new->next;
	}
	if (!new)
	{
		new = a;
		while (new && new->index > largest)
		{
			largest = new->index;
			new->is_a = 1;
			new = new->next;
		}
	}
}
