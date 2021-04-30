/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:53:09 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/29 21:49:09 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					get_smallest(t_stack *stack)
{
	t_stack			*new;
	int				smallest;

	smallest = stack->index;
	new = stack;
	while (new)
	{
		if (new->index < smallest)
			smallest = new->index;
		new = new->next;
	}
	return (smallest);
}

void				move_smallest_to_first(t_stack **stack)
{
	t_stack			*new;
	int				count;
	int				smallest;
	int				idx;

	new = *stack;
	count = 0;
	smallest = get_smallest(*stack);
	while (new && new->index != smallest)
	{
		new = new->next;
		count++;
	}
	count++;
	idx = -1;
	if (count < (stack_size(*stack) / 2))
		while (++idx < count)
			ft_rotate(NULL, stack, TAG_B);
	else
		while (++idx < stack_size(*stack) - count + 1)
			ft_rev_rotate(NULL, stack, TAG_B);
}

int					check_swap_effect(t_stack **a, t_stack **b, int mark)
{
	ft_swap(a, b, TAG_A);
	set_markup(*a);
	if (count_markup(*a) <= mark)
	{
		ft_swap(a, b, TAG_A);
		set_markup(*a);
		return (FALSE);
	}
	else
		return (TRUE);
}

void				a_to_b(t_stack **a, t_stack **b)
{
	int				mark;

	while ((mark = count_markup(*a)) != stack_size(*a))
	{
		if (check_swap_effect(a, b, mark) == 1)
			write(1, "sa\n", 3);
		else if ((*a)->is_a == 0)
		{
			ft_push(a, b, TAG_B);
			write(1, "pb\n", 3);
		}
		else
		{
			ft_rotate(a, b, TAG_A);
			write(1, "ra\n", 3);
		}
		print_stack_with_opt(*a, *b);
	}
}

void				sorting(t_stack **a, t_stack **b)
{

	while (!(check_order(*a) == 1 && stack_size(*b) == 0))
	{
		a_to_b(a, b);
		move_smallest_to_first(a);
		printf(">>\n");
		print_stack_with_opt(*a, *b);
		break ;

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
	set_markup(a);
	sorting(&a, &b);
}
