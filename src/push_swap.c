/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:53:09 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/30 20:02:45 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					set_headmark(t_stack **a)
{

}

void				sorting_size(t_stack **a, t_stack **b, t_res **res)
{
	int				mark;

	mark = set_headmark(a);
}

void				sorting(t_stack **a, t_stack **b)
{
	t_res			*res_one;
	t_res			*res_two;

	// res_one = init_operation(-1);
	// sorting_index(a, b, &res_one);
	// refactoring_res(res_one);
	// print_operation(res_one);
	res_two = init_operation(-1);
	sorting_size(a, b, &res_two);
}

int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	if (argc < 2)
		return (0);
	set_num(argc - 1, argv, &a);
	set_index(a);
	set_markup(a);
	sorting(&a, &b);
}
