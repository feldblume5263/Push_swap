/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:49:30 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/30 17:50:02 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void				move_largest_to_first(t_stack **stack, t_res **res)
{
	t_stack			*new;
	int				count;
	int				largest;
	int				idx;

	new = *stack;
	largest = get_largest(*stack);
	count = get_index_order(new, largest);
	idx = -1;
	if (count > (stack_size(*stack) / 2))
		while (++idx < stack_size(*stack) - count + 1)
		{
			add_operation(res, RRB);
			ft_rev_rotate(NULL, stack, TAG_B);
		}
	else
		while (++idx < count - 1)
		{
			add_operation(res, RB);
			ft_rotate(NULL, stack, TAG_B);
		}
}

void				move_smallest_to_first(t_stack **stack, t_res **res)
{
	t_stack			*new;
	int				count;
	int				smallest;
	int				idx;

	new = *stack;
	smallest = get_smallest(*stack);
	count = get_index_order(new, smallest);
	idx = -1;
	if (count > (stack_size(*stack) / 2))
		while (++idx < stack_size(*stack) - count + 1)
		{
			add_operation(res, RRA);
			ft_rev_rotate(NULL, stack, TAG_B);
		}
	else
		while (++idx < count - 1)
		{
			add_operation(res, RA);
			ft_rotate(NULL, stack, TAG_B);
		}
}

int					check_swap_effect(t_stack **a, t_stack **b, int mark)
{
	ft_swap(a, b, TAG_A);
	set_markup(*a);
	if (count_markup(*a) <= mark)
	{
		ft_swap(a, b, TAG_A);
		set_markup(*a);
		return (FALSE);
	}
	else
		return (TRUE);
}

void				a_to_b(t_stack **a, t_stack **b, t_res **res)
{
	int				mark;

	while ((mark = count_markup(*a)) != stack_size(*a))
	{
		if (check_swap_effect(a, b, mark) == 1)
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

void				sorting_index(t_stack **a, t_stack **b, t_res **res)
{
	a_to_b(a, b, res);
	move_smallest_to_first(a, res);
	while (!(stack_size(*b) == 0))
	{
		move_largest_to_first(b, res);
		ft_push(a, b, TAG_A);
		add_operation(res, PA);
	}
	move_smallest_to_first(a, res);
}
