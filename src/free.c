/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:53:14 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 22:14:02 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ANCHOR 에러메세지 전부 ERROR로 수정

void				refactoring_res2(t_res *cmp, t_res *new)
{
	cmp = new->next;
	while (cmp && !((cmp->op >= 6 && cmp->op <= 10)\
			|| (cmp->op >= 0 && cmp->op <= 2)))
		cmp = cmp->next;
	if (cmp && cmp->op == new->op - 3)
	{
		new->op += 5;
		cmp->op = -1;
	}
}

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
			refactoring_res2(cmp, new);
		}
		new = new->next;
	}
}

void				stack_delete(t_stack **stack)
{
	t_stack			*temp;

	temp = stack_last(*stack);
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
}

void				free_res(t_res **stack)
{
	t_res			*temp;

	while (*stack)
	{
		temp = NULL;
		if ((*stack)->next)
			temp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = temp;
	}
}

void				free_stack(t_stack **stack)
{
	t_stack			*temp;

	while (*stack)
	{
		temp = NULL;
		if ((*stack)->next)
			temp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = temp;
	}
}
