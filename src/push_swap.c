/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:53:09 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/01 12:49:06 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					set_headmark(t_stack *a)
{
	int				temp;
	int				count;
	t_stack			*new;
	t_stack			*start;
	int				largest;
	int				ret_index;

	new = a;
	largest = 0;
	while (new)
	{
		temp = new->index;
		start = new->next;
		count = 1;
		while (start && start->index > temp)
		{
			count++;
			temp = start->index;
			start = start->next;
		}
		if (!start)
		{
			start = a;
			while (start && start->index > temp)
			{
				count++;
				temp = start->index;
				start = start->next;
			}
		}
		if (largest < count)
		{
			largest = count;
			ret_index = new->index;
		}
		new = new->next;
	}
	printf("(%d)\n", largest);
	return (ret_index);
}

void				sorting_size(t_stack **a, t_stack **b, t_res **res)
{
	int				mark;

	printf("mark: 0\n");
	mark = set_headmark(*a);
	printf("mark: %d\n", mark);
}

void				sorting(t_stack **a, t_stack **b)
{
	t_res			*res_one;
	t_res			*res_two;

	// set_markup(a);
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
	sorting(&a, &b);
}
