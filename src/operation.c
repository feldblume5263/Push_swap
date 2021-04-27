/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:50:33 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/27 16:36:57 by junhpark         ###   ########.fr       */
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


