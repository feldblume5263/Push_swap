/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:59:03 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/28 12:52:52 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack				*pop(t_stack **stack)
{
	t_stack			*temp;
	t_stack			*ret;

	if (*stack == NULL)
		return (NULL);
	ret = stack_init((*stack)->content);
	ret->index = (*stack)->index;
	ret->is_a = (*stack)->is_a;
	temp = (*stack)->next;
	free (*stack);
	*stack = temp;
	return (ret);
}

void				rotate(t_stack **stack)
{
	stack_add_back(stack, pop(stack));
}

// 이 부분을 좀 더 깔끔히?
void				reverse_rotate(t_stack **stack)
{
	int				size;
	int				idx;

	size = stack_size(*stack);
	idx = 0;
	while (idx < size - 1)
	{
		rotate(stack);
		idx++;
	}
}

void				push(t_stack **stack, t_stack *new)
{
	stack_add_front(stack, new);
}
