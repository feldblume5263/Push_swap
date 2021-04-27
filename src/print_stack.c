/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:38:23 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/27 16:38:47 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				print_stack(t_stack *a, t_stack *b)
{
	t_stack			*new;

	new = a;
	printf("A | ");
	while (new)
	{
		printf("%d ", new->content);
		new = new->next;
	}
	printf("\n");
	new = b;
	printf("B | ");
	while (new)
	{
		printf("%d ", new->content);
		new = new->next;
	}
	printf("\n");
	printf("\n");
	printf("\n");
}
