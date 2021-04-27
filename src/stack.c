/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:59:03 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/27 21:19:27 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	만약에 아무것도 없을 때 반환하는 0이 문제가 된다면,
**	구조체를 반환해서 비어있다는 인자를 포함시킬 수 있다.
*/

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
