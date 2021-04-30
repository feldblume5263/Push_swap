/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:53:09 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/30 17:16:25 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void				refactoring_res(t_res *res)
{
	t_res			*new;
	t_res			*cmp;

	new = res;
	while (new)
	{
		if (new->op >= 0 && new->op <= 2)
		{
			cmp = new->next;
			while (cmp && !(cmp->op >= 3 && cmp->op <= 10))
				cmp = cmp->next;
			if (cmp && cmp->op == new->op + 3)
			{
				new->op += 8;
				cmp->op = -1;
			}
		}
		if (new->op >= 3 && new->op <= 5)
		{
			cmp = new->next;
			while (cmp && !((cmp->op >= 6 && cmp->op <= 10) || (cmp->op >= 0 && cmp->op <= 2)))
				cmp = cmp->next;
			if (cmp && cmp->op == new->op - 3)
			{
				new->op += 5;
				cmp->op = -1;
			}
		}
		new = new->next;
	}
}

void				sorting(t_stack **a, t_stack **b)
{
	t_res			*res_one;

	res_one = init_operation(-1);
	sorting_index(a, b, &res_one);
	refactoring_res(res_one);
	print_operation(res_one);
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
	sorting(&a, &b);
}
