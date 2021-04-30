/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:06:54 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/30 16:34:17 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_res				*operation_last(t_res *stack)
{
	t_res			*new;

	new = stack;
	while (new && new->next)
	{
		new = new->next;
	}
	return (new);
}

void				print_by_num(t_res *new)
{
	if (new->op == SA)
		write(1, "sa\n", 3);
	else if (new->op == SB)
		write(1, "sb\n", 3);
	else if (new->op == SS)
		write(1, "ss\n", 3);
	else if (new->op == PA)
		write(1, "pa\n", 3);
	else if (new->op == PB)
		write(1, "pb\n", 3);
	else if (new->op == RA)
		write(1, "ra\n", 3);
	else if (new->op == RB)
		write(1, "rb\n", 3);
	else if (new->op == RR)
		write(1, "rr\n", 3);
	else if (new->op == RRA)
		write(1, "rra\n", 4);
	else if (new->op == RRB)
		write(1, "rrb\n", 4);
	else if (new->op == RRR)
		write(1, "rrr\n", 5);
}

void				print_operation(t_res *stack)
{
	t_res			*new;

	new = stack;
	while (new)
	{
		print_by_num(new);
		new = new->next;
	}
}

t_res				*init_operation(int	operation)
{
	t_res			*n_stack;

	if (!(n_stack = ft_calloc(1, sizeof(t_res))))
		return (0);
	n_stack->op = operation;
	n_stack->next = 0;
	return (n_stack);
}


void				add_operation(t_res **stack, int operation)
{
	t_res			*p;
	t_res			*new;

	new = init_operation(operation);
	p = operation_last(*stack);
	if (p)
		p->next = new;
	else
		*stack = new;
}
