/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:53:09 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/27 22:12:50 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				set_index(t_stack *stack)
{
	t_stack			*temp;
	t_stack			*start;
	int				count;

	start = stack;
	while (stack)
	{
		temp = start;
		count = 0;
		while (temp)
		{
			if (temp->content < stack->content)
				count++;
			temp = temp->next;
		}
		stack->index = count;
		stack = stack->next;
	}
}

int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	if (argc < 2)
		return (0);
	set_num(argc - 1, argv, &a);
	set_index(a);

}
