/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:50:33 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/07 20:19:31 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_rev_rotate(t_stack **a, t_stack **b, int tag)
{
	if (tag == TAG_A)
		reverse_rotate(a);
	else if (tag == TAG_B)
		reverse_rotate(b);
	else if (tag == TAG_ALL)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void				ft_rotate(t_stack **a, t_stack **b, int tag)
{
	if (tag == TAG_A)
		rotate(a);
	else if (tag == TAG_B)
		rotate(b);
	else if (tag == TAG_ALL)
	{
		rotate(a);
		rotate(b);
	}
}

void				ft_push(t_stack **a, t_stack **b, int tag)
{
	if (tag == TAG_A)
	{

	}
	else if (tag == TAG_B)
	{

	}
	else if (tag == TAG_ALL)
	{

	}
}

void				ft_swap(t_stack **a, t_stack **b, int tag)
{
	t_stack			*temp;

	if (tag == TAG_A)
	{
		if (stack_size(*a) < 2)
			return ;

	}
	else if (tag == TAG_B)
	{
		if (stack_size(*b) < 2)
			return ;
	}
	else if (tag == TAG_ALL)
	{
		if (stack_size(*a) < 2 || stack_size(b) < 2)
			return ;
	}
}

void				run_operation(char *opt, t_stack **a, t_stack **b)
{
	if (ft_strlen(opt) == 2 && ft_strncmp(opt, "sa", 2) == 0)
		printf("%s\n", opt);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "sb", 2) == 0)
		printf("%s\n", opt);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "ss", 2) == 0)
		printf("%s\n", opt);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "pa", 2) == 0)
		printf("%s\n", opt);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "pb", 2) == 0)
		printf("%s\n", opt);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "ra", 2) == 0)
		printf("%s\n", opt);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "rb", 2) == 0)
		printf("%s\n", opt);
	else if (ft_strlen(opt) == 2 && ft_strncmp(opt, "rr", 2) == 0)
		printf("%s\n", opt);
	else if (ft_strlen(opt) == 3 && ft_strncmp(opt, "rra", 3) == 0)
		printf("%s\n", opt);
	else if (ft_strlen(opt) == 3 && ft_strncmp(opt, "rrb", 3) == 0)
		printf("%s\n", opt);
	else if (ft_strlen(opt) == 3 && ft_strncmp(opt, "rrr", 3) == 0)
		printf("%s\n", opt);
	else
		exit_with_error(1);
}
