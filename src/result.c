/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:06:54 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 19:21:59 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					count_operation_final(t_res *operation)
{
	int				count;

	count = 0;
	while (operation)
	{
		if (operation->op > -1)
			count++;
		operation = operation->next;
	}
	return (count);
}

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

t_res				*init_operation(int operation)
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
