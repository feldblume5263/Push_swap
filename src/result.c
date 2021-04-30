/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:06:54 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/30 17:47:54 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				refactoring_res(t_res *res)
{
	t_res			*new;
	t_res			*cmp;

	new = res;
	while (new)
	{
		if (new->op >= 0 && new->op <= 2)
		{
			cmp = new->next;
			while (cmp && !(cmp->op >= 3 && cmp->op <= 10))
				cmp = cmp->next;
			if (cmp && cmp->op == new->op + 3)
			{
				new->op += 8;
				cmp->op = -1;
			}
		}
		if (new->op >= 3 && new->op <= 5)
		{
			cmp = new->next;
			while (cmp && !((cmp->op >= 6 && cmp->op <= 10) || (cmp->op >= 0 && cmp->op <= 2)))
				cmp = cmp->next;
			if (cmp && cmp->op == new->op - 3)
			{
				new->op += 5;
				cmp->op = -1;
			}
		}
		new = new->next;
	}
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
