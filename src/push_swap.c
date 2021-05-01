/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:53:09 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/01 20:29:53 by junhpark         ###   ########.fr       */
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

void				size_run_operation(t_stack **a, t_stack **b, int opt)
{
	if (opt == SA)
		ft_swap(a, b, TAG_A);
	else if (opt == SB)
		ft_swap(a, b, TAG_B);
	else if (opt == SS)
		ft_swap(a, b, TAG_ALL);
	else if (opt == PA)
		ft_push(a, b, TAG_A);
	else if (opt == PB)
		ft_push(a, b, TAG_B);
	else if (opt == RA)
		ft_rotate(a, b, TAG_A);
	else if (opt == RB)
		ft_rotate(a, b, TAG_B);
	else if (opt == RR)
		ft_rotate(a, b, TAG_ALL);
	else if (opt == RRA)
		ft_rev_rotate(a, b, TAG_A);
	else if (opt == RRB)
		ft_rev_rotate(a, b, TAG_B);
	else if (opt == RRR)
		ft_rev_rotate(a, b, TAG_ALL);
}


void				calculate_test(t_stack **a, t_stack **b, int *test, int operation)
{
	int				gap;
	
	size_run_operation(a, b, operation);
	gap = get_gap((*a)->index, (*b)->index);
	if (gap < test[0])
	{
		test[0] = gap;
		test[1] = operation;
	}
}

int					prepare_move(t_stack **a, t_stack **b)
{
	int				test[2];

	test[0] = get_gap((*a)->index, (*b)->index);
	test[1] = -1;
	calculate_test(a, b, test, SB);
	ft_swap(a, b, TAG_B);
	calculate_test(a, b, test, RA);
	ft_rev_rotate(a, b, TAG_A);
	calculate_test(a, b, test, RB);
	ft_rev_rotate(a, b, TAG_B);
	calculate_test(a, b, test, RR);
	ft_rev_rotate(a, b, TAG_ALL);
	calculate_test(a, b, test, RRA);
	ft_rotate(a, b, TAG_A);
	calculate_test(a, b, test, RRB);
	ft_rotate(a, b, TAG_B);
	calculate_test(a, b, test, RRR);
	ft_rotate(a, b, TAG_ALL);
	return (test[1]);
}

// FIXME 여기서 두개 바꿔가면서 작은 수 찾기
void				rotate_a_to_put(t_stack **a, t_stack **b, t_res **res)
{
	print_stack_index(*a, *b);
	while (!(((*a)->index > (*b)->index) && (stack_last(*a)->index < (*b)->index)))
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

void				size_b_to_a(t_stack **a, t_stack **b, t_res **res)
{
	int				idx;
	int				operation;

	idx = 0;
	while (idx < stack_size(*b))
	{
		operation = prepare_move(a, b);
		size_run_operation(a, b, operation);
		add_operation(res, operation);
		idx++;
	}
	rotate_a_to_put(a, b, res);
}

void				set_size_mark(t_stack *a, int headmark)
{
	t_stack			*new;
	int				largest;

	new = a;
	while (new)
	{
		new->is_a = 0;
		new = new->next;
	}
	new = a;
	while (new)
	{
		if (new->index == headmark)
		{
			new->is_a = 1;
			new = new->next;
			break;
		}
		new = new->next;
	}
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

int					set_headmark(t_stack *a)
{
	int				temp;
	int				count;
	t_stack			*new;
	t_stack			*start;
	int				largest;
	int				ret_index;

	new = a;
	largest = 0;
	while (new)
	{
		temp = new->index;
		start = new->next;
		count = 1;
		while (start && start->index > temp)
		{
			count++;
			temp = start->index;
			start = start->next;
		}
		if (!start)
		{
			start = a;
			while (start && start->index > temp)
			{
				count++;
				temp = start->index;
				start = start->next;
			}
		}
		if (largest < count)
		{
			largest = count;
			ret_index = new->index;
		}
		new = new->next;
	}
	return (ret_index);
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
	print_operation(*res);
}

void				sorting(t_stack **a, t_stack **b)
{
	t_res			*res_one;
	t_res			*res_two;

	// set_markup(a);
	// res_one = init_operation(-1);
	// sorting_index(a, b, &res_one);
	// refactoring_res(res_one);
	// print_operation(res_one);
	res_two = init_operation(-1);
	sorting_size(a, b, &res_two);
}

int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	if (argc < 2)
		return (0);
	set_num(argc - 1, argv, &a);
	set_index(a);
	sorting(&a, &b);
}
