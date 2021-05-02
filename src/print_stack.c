/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:38:23 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 19:09:04 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void				print_stack_index(t_stack *a, t_stack *b)
{
	t_stack			*new;

	new = a;
	write(1, "A | ", 4);
	while (new)
	{
		ft_putnbr_fd(new->index, 1);
		new = new->next;
	}
	write(1, "\n", 1);
	new = b;
	write(1, "B | ", 4);
	while (new)
	{
		ft_putnbr_fd(new->index, 1);
		new = new->next;
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
}

void				print_stack(t_stack *a, t_stack *b)
{
	t_stack			*new;

	new = a;
	write(1, "A | ", 4);
	while (new)
	{
		ft_putnbr_fd(new->content, 1);
		new = new->next;
	}
	write(1, "\n", 1);
	new = b;
	write(1, "B | ", 4);
	while (new)
	{
		ft_putnbr_fd(new->content, 1);
		new = new->next;
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
}
