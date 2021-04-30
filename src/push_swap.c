/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:53:09 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/30 14:52:27 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				move_largest_to_first(t_stack **stack)
{
	t_stack			*new;
	int				count;
	int				largest;
	int				idx;

	new = *stack;
	largest = get_largest(*stack);
	count = get_index_order(new, largest);
	idx = -1;
	if (count < (stack_size(*stack) / 2))
		while (++idx < count - 1)
		{
			write(1, "rb\n", 3);
			ft_rotate(NULL, stack, TAG_B);
		}
	else
		while (++idx < stack_size(*stack) - count + 1)
		{
			write(1, "rrb\n", 4);
			ft_rev_rotate(NULL, stack, TAG_B);
		}
}

void				move_smallest_to_first(t_stack **stack)
{
	t_stack			*new;
	int				count;
	int				smallest;
	int				idx;

	new = *stack;
	smallest = get_smallest(*stack);
	count = get_index_order(new, smallest);
	idx = -1;
	if (count <= (stack_size(*stack) / 2))
		while (++idx < count - 1)
		{
			write(1, "ra\n", 3);
			ft_rotate(NULL, stack, TAG_B);
		}
	else
		while (++idx < stack_size(*stack) - count + 1)
		{
			write(1, "rra\n", 4);
			ft_rev_rotate(NULL, stack, TAG_B);
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

void				a_to_b(t_stack **a, t_stack **b)
{
	int				mark;

	while ((mark = count_markup(*a)) != stack_size(*a))
	{
		if (check_swap_effect(a, b, mark) == 1)
			write(1, "sa\n", 3);
		else if ((*a)->is_a == 0)
		{
			ft_push(a, b, TAG_B);
			write(1, "pb\n", 3);
		}
		else
		{
			ft_rotate(a, b, TAG_A);
			write(1, "ra\n", 3);
		}
	}
}

void				sorting_index(t_stack **a, t_stack **b, t_stack *ret)
{
	a_to_b(a, b);
	move_smallest_to_first(a);
	while (!(stack_size(*b) == 0))
	{
		move_largest_to_first(b);
		ft_push(a, b, TAG_A);
		write(1, "pa\n", 3);
	}
	move_smallest_to_first(a);
}

int					sorting(t_stack **a, t_stack **b)
{
	t_stack			*ret_index;

	sorting_index(a, b, ret_index);
}

int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	if (argc < 2)
		return (0);
	set_num(argc - 1, argv, &a);
	set_index(a);
	set_markup(a);
	sorting_index(&a, &b);
}
