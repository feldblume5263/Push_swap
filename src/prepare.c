/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:28:49 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 18:37:20 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	size_run_operation(t_stack **a, t_stack **b, int opt)
{
	if (opt == SA)
		ft_swap(a, b, TAG_A);
	else if (opt == SB)
		ft_swap(a, b, TAG_B);
	else if (opt == SS)
		ft_swap(a, b, TAG_ALL);
	else if (opt == PA)
		ft_push(a, b, TAG_A);
	else if (opt == PB)
		ft_push(a, b, TAG_B);
	else if (opt == RA)
		ft_rotate(a, b, TAG_A);
	else if (opt == RB)
		ft_rotate(a, b, TAG_B);
	else if (opt == RR)
		ft_rotate(a, b, TAG_ALL);
	else if (opt == RRA)
		ft_rev_rotate(a, b, TAG_A);
	else if (opt == RRB)
		ft_rev_rotate(a, b, TAG_B);
	else if (opt == RRR)
		ft_rev_rotate(a, b, TAG_ALL);
}

void
	calculate_test(t_stack **a, t_stack **b, int *test, int operation)
{
	int				gap;

	size_run_operation(a, b, operation);
	gap = get_gap((*a)->index, (*b)->index);
	if (gap < test[0])
	{
		test[0] = gap;
		test[1] = operation;
	}
}

int
	prepare_move(t_stack **a, t_stack **b)
{
	int				test[2];

	test[0] = get_gap((*a)->index, (*b)->index);
	test[1] = -1;
	calculate_test(a, b, test, SB);
	ft_swap(a, b, TAG_B);
	calculate_test(a, b, test, RA);
	ft_rev_rotate(a, b, TAG_A);
	calculate_test(a, b, test, RB);
	ft_rev_rotate(a, b, TAG_B);
	calculate_test(a, b, test, RR);
	ft_rev_rotate(a, b, TAG_ALL);
	calculate_test(a, b, test, RRA);
	ft_rotate(a, b, TAG_A);
	calculate_test(a, b, test, RRB);
	ft_rotate(a, b, TAG_B);
	calculate_test(a, b, test, RRR);
	ft_rotate(a, b, TAG_ALL);
	return (test[1]);
}
