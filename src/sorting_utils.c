/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:48:42 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/30 14:49:30 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					get_index_order(t_stack *new, int index)
{
	int				count;

	count = 0;
	while (new && new->index != index)
	{
		new = new->next;
		count++;
	}
	count++;
	return (count);
}

int					get_smallest(t_stack *stack)
{
	t_stack			*new;
	int				smallest;

	smallest = stack->index;
	new = stack;
	while (new)
	{
		if (new->index < smallest)
			smallest = new->index;
		new = new->next;
	}
	return (smallest);
}

int					get_largest(t_stack *stack)
{
	t_stack			*new;
	int				largest;

	largest = stack->index;
	new = stack;
	while (new)
	{
		if (new->index > largest)
			largest = new->index;
		new = new->next;
	}
	return (largest);
}
