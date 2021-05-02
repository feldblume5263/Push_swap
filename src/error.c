/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:48:39 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 18:31:02 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				check_dup_error(t_stack *a)
{
	t_stack			*compare;

	while (a)
	{
		compare = a->next;
		while (compare)
		{
			if (compare->content == a->content)
				exit_with_error(3);
			compare = compare->next;
		}
		a = a->next;
	}
}

void				exit_with_error(int errno)
{
	if (errno == 1)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	else if (errno == 2)
	{
		write(1, "MEM_ERROR\n", 10);
		exit(2);
	}
	else if (errno == 3)
	{
		write(1, "DUP_ERROR\n", 10);
		exit(2);
	}
}

int					is_string_digit(char *str)
{
	int				idx;
	int				count;

	idx = 0;
	count = 0;
	while (str[idx])
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
			count++;
		idx++;
	}
	return (count);
}
