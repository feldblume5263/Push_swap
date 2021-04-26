/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:18:45 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/26 20:23:49 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					check_order(t_stack *stack)
{
	t_stack			*new;
	int				temp;

	new = stack;
	temp = new->content;
	while (new)
	{
		if (temp > new->content)
			return (0);
		new = new->next;
	}
	return (1);
}

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

void				get_operation(t_stack **a, t_stack **b)
{
	int				flag;
	char			*line;

	while (1)
	{
		if ((flag = get_next_line(&line)) < 0)
			exit_with_error(2);
		if (!(run_operation(line, a, b)))
			break ;
		print_stack(*a, *b);
		free(line);
		line = NULL;
	}
	if (check_order(*a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void				get_num(int max, char **num, t_stack **a)
{
	int				idx;

	idx = 1;
	while (idx <= max)
	{
		if (!(is_string_digit(num[idx])))
			exit_with_error(1);
		stack_add_back(a, stack_init(ft_atoi(num[idx])));
		idx++;
	}
}

// 정수형 범위 초과, 중복 검사 해야함.
int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	get_num(argc - 1, argv, &a);
	get_operation(&a, &b);
}
