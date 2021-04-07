/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:18:45 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/07 19:51:24 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				get_operation(t_stack **a, t_stack **b)
{
	int				flag;
	char			*line;

	while (1)
	{
		if ((flag = get_next_line(&line)) < 0)
			exit_with_error(2);
		run_operation(line, a, b);
		free(line);
		line = NULL;
	}
}

void				get_num(int max, char **num, t_stack **a)
{
	int				idx;

	idx = 1;
	while (idx <= max)
	{
		if (!(is_string_digit(num[idx])))
			exit_with_error(1);
		push(a, ft_atoi(num[idx]));
		idx++;
	}
}

// 정수형 범위 초과, 중복 검사 해야함.
int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	get_num(argc - 1, argv, &a);
	reverse_rotate(&a);
	printf("??\n");
	// get_operation(&a, &b);
}
