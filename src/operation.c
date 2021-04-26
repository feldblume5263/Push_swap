/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:50:33 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/26 18:51:54 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_rev_rotate(t_stack **a, t_stack **b, int tag)
{
	if (tag == TAG_A || tag == TAG_ALL)
	{
		if (stack_size(*a) < 1)
			return ;
		reverse_rotate(a);
	}
	if (tag == TAG_B || tag == TAG_ALL)
	{
		if (stack_size(*b) < 1)
			return ;
		reverse_rotate(b);
	}
}

void				ft_rotate(t_stack **a, t_stack **b, int tag)
{
	if (tag == TAG_A || tag == TAG_ALL)
	{
		if (stack_size(*a) < 1)
			return ;
		rotate(a);
	}
	if (tag == TAG_B || tag == TAG_ALL)
	{
		if (stack_size(*b) < 1)
			return ;
		rotate(b);
	}
}

void				ft_push(t_stack **a, t_stack **b, int tag)
{
	if (tag == TAG_A)
	{
		if (stack_size(*b) < 1)
			return ;
		push(a, pop(b));
	}
	else if (tag == TAG_B)
	{
		if (stack_size(*a) < 1)
			return ;
		push(b, pop(a));
	}
}

void				ft_swap(t_stack **a, t_stack **b, int tag)
{
	t_stack			*temp;
	int				up;
	int				down;

	if (tag == TAG_A || tag == TAG_ALL)
	{
		if (stack_size(*a) < 2)
			return ;
		up = pop(a);
		down = pop(a);
		push(a, up);
		push(a, down);

	}
	if (tag == TAG_B || tag == TAG_ALL)
	{
		if (stack_size(*b) < 2)
			return ;
		up = pop(b);
		down = pop(b);
		push(b, up);
		push(b, down);
	}
}

int					run_operation(char *opt, t_stack **a, t_stack **b)
{
	if (ft_strlen(opt) == 2 && ft_strncmp(opt, "sa", 2) == 0)
		ft_swap(a, b, TAG_A);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "sb", 2) == 0)
		ft_swap(a, b, TAG_B);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "ss", 2) == 0)
		ft_swap(a, b, TAG_ALL);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "pa", 2) == 0)
		ft_push(a, b, TAG_A);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "pb", 2) == 0)
		ft_push(a, b, TAG_B);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "ra", 2) == 0)
		ft_rotate(a, b, TAG_A);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "rb", 2) == 0)
		ft_rotate(a, b, TAG_B);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "rr", 2) == 0)
		ft_rotate(a, b, TAG_ALL);
	else if (ft_strlen(opt) == 3 && ft_strncmp(opt, "rra", 3) == 0)
		ft_rev_rotate(a, b, TAG_A);
	else if (ft_strlen(opt) == 3 && ft_strncmp(opt, "rrb", 3) == 0)
		ft_rev_rotate(a, b, TAG_B);
	else if (ft_strlen(opt) == 3 && ft_strncmp(opt, "rrr", 3) == 0)
		ft_rev_rotate(a, b, TAG_ALL);
	else if (*opt == '\0')
		return (0);
	else
		exit_with_error(1);
	return (1);
}
