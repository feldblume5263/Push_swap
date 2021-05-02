/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:51:38 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 19:28:10 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	count_markup(t_stack *stack)
{
	t_stack			*new;
	int				count;

	new = stack;
	count = 0;
	while (new)
	{
		if (new->is_a == 1)
			count++;
		new = new->next;
	}
	return (count);
}

void
	set_tag(t_stack *new, int *tag)
{
	if (new->index == (*tag) + 1)
	{
		new->is_a = 1;
		(*tag) = (*tag) + 1;
	}
	else
		new->is_a = 0;
}

void
	set_markup(t_stack *stack)
{
	t_stack			*new;
	int				tag;

	new = stack;
	tag = -1;
	while (new)
	{
		if (tag >= 0)
			set_tag(new, &tag);
		if (new->index == 0)
		{
			new->is_a = 1;
			tag = 0;
		}
		new = new->next;
	}
	new = stack;
	while (new)
	{
		if (new->index == 0)
			break ;
		set_tag(new, &tag);
		new = new->next;
	}
}

void
	set_headmark2(t_stack *a, t_stack *start, t_stack *new, int *idx)
{
	if (!start)
	{
		start = a;
		while (start && start->index > idx[0])
		{
			idx[1]++;
			idx[0] = start->index;
			start = start->next;
		}
	}
	if (idx[2] < idx[1])
	{
		idx[2] = idx[1];
		idx[3] = new->index;
	}
}

int
	set_headmark(t_stack *a)
{
	int				idx[4];
	t_stack			*new;
	t_stack			*start;

	new = a;
	idx[2] = 0;
	while (new)
	{
		idx[0] = new->index;
		start = new->next;
		idx[1] = 1;
		while (start && start->index > idx[0])
		{
			idx[1]++;
			idx[0] = start->index;
			start = start->next;
		}
		set_headmark2(a, start, new, idx);
		new = new->next;
	}
	return (idx[3]);
}
