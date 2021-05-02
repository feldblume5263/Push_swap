/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:33:44 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 18:53:44 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack			*p;

	p = stack_last(*stack);
	if (p)
		p->next = new;
	else
		*stack = new;
}

void				stack_add_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

int					stack_size(t_stack *stack)
{
	t_stack			*new;
	unsigned int	count;

	new = stack;
	count = 0;
	while (new)
	{
		new = new->next;
		count++;
	}
	return (count);
}

t_stack				*stack_last(t_stack *stack)
{
	t_stack			*new;

	new = stack;
	while (new && new->next)
		new = new->next;
	return (new);
}

t_stack				*stack_init(int content)
{
	t_stack			*n_stack;

	if (!(n_stack = ft_calloc(1, sizeof(t_stack))))
		return (0);
	n_stack->content = content;
	n_stack->next = 0;
	n_stack->index = -1;
	n_stack->is_a = 0;
	return (n_stack);
}
