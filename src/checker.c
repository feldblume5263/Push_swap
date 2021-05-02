/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:12:08 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 20:27:57 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					run_operation2(char *opt, t_stack **a, t_stack **b)
{
	if (ft_strlen(opt) == 2 && ft_strncmp(opt, "ra", 2) == 0)
		ft_rotate(a, b, TAG_A);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "rb", 2) == 0)
		ft_rotate(a, b, TAG_B);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "rr", 2) == 0)
		ft_rotate(a, b, TAG_ALL);
	else if (ft_strlen(opt) == 3 && ft_strncmp(opt, "rra", 3) == 0)
		ft_rev_rotate(a, b, TAG_A);
	else if (ft_strlen(opt) == 3 && ft_strncmp(opt, "rrb", 3) == 0)
		ft_rev_rotate(a, b, TAG_B);
	else if (ft_strlen(opt) == 3 && ft_strncmp(opt, "rrr", 3) == 0)
		ft_rev_rotate(a, b, TAG_ALL);
}

int					run_operation(char *opt, t_stack **a, t_stack **b)
{
	if (ft_strlen(opt) == 2 && ft_strncmp(opt, "sa", 2) == 0)
		ft_swap(a, b, TAG_A);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "sb", 2) == 0)
		ft_swap(a, b, TAG_B);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "ss", 2) == 0)
		ft_swap(a, b, TAG_ALL);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "pa", 2) == 0)
		ft_push(a, b, TAG_A);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "pb", 2) == 0)
		ft_push(a, b, TAG_B);
	else if (1)
		run_operation2(opt, a, b);
	else if (*opt == '\0')
		return (0);
	else
		exit_with_error(1);
	return (1);
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
	if (check_order(*a) == 1 && stack_size(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

// TODO 정수형 범위 초과, 중복 검사 해야함.
int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	if (argc < 2)
		return (0);
	set_num(argc - 1, argv, &a);
	check_dup_error(a);
	get_operation(&a, &b);
}
