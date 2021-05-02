/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:53:09 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 18:39:52 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	sorting(t_stack **a, t_stack **b, t_stack **dup_a, t_stack **dup_b)
{
	t_res			*res_one;
	t_res			*res_two;

	set_markup(*a);
	res_one = init_operation(-1);
	sorting_index(a, b, &res_one);
	refactoring_res(res_one);
	res_two = init_operation(-1);
	sorting_size(dup_a, dup_b, &res_two);
	refactoring_res(res_two);
	if (count_operation_final(res_one) <= count_operation_final(res_two))
		print_operation(res_one);
	else
		print_operation(res_two);
}

void
	dup_stack(t_stack *stack, t_stack **ret)
{
	int				idx;
	int				size;
	t_stack			*new;

	size = stack_size(stack);
	idx = 0;
	new = stack;
	while (idx < size)
	{
		stack_add_back(ret, stack_init(new->content));
		stack_last(*ret)->index = new->index;
		new = new->next;
		idx++;
	}
}

int
	main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*dup_a;
	t_stack			*dup_b;

	if (argc < 2)
		return (0);
	set_num(argc - 1, argv, &a);
	if (argc < 3)
		return (0);
	check_dup_error(a);
	set_index(a);
	dup_stack(a, &dup_a);
	dup_stack(b, &dup_b);
	sorting(&a, &b, &dup_a, &dup_b);
}
