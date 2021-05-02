/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:54:43 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 20:26:39 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define TAG_A		1
# define TAG_B		2
# define TAG_ALL	3
# define TRUE		1
# define FALSE		0

# define SA			0
# define RA			1
# define RRA		2
# define SB			3
# define RB			4
# define RRB		5
# define PA			6
# define PB			7
# define SS			8
# define RR			9
# define RRR		10

typedef struct		s_res
{
	int				op;
	struct s_res	*next;
}					t_res;

typedef struct		s_stack
{
	int				content;
	int				index;
	int				is_a;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_input
{
	int				max;
}					t_input;

/*
**	checker.c
*/
void				get_operation(t_stack **a, t_stack **b);
int					run_operation(char *opt, t_stack **a, t_stack **b);
void				run_operation2(char *opt, t_stack **a, t_stack **b);

/*
**	push_swap.c
*/
void				dup_stack(t_stack *stack, t_stack **ret);
void				sorting(t_stack **a, t_stack **b,\
						t_stack **dup_a, t_stack **dup_b);

/*
**	sort_by_index.c
*/
void				sorting_index(t_stack **a, t_stack **b, t_res **res);
void				a_to_b(t_stack **a, t_stack **b, t_res **res);
int					check_swap_effect(t_stack **a, t_stack **b, int mark);
void				move_smallest_to_first(t_stack **stack, t_res **res);
void				move_largest_to_first(t_stack **stack, t_res **res);

/*
**	sort_by_size.c
*/
void				sorting_size(t_stack **a, t_stack **b, t_res **res);
void				size_a_to_b(t_stack **a, t_stack **b, t_res **res);
int					size_check_swap_effect(t_stack **a, t_stack **b, int mark);
void				set_size_mark(t_stack *a, int headmark);
void				size_b_to_a(t_stack **a, t_stack **b, t_res **res);

/*
**	prepare.c
*/
int					prepare_move(t_stack **a, t_stack **b);
void				calculate_test(t_stack **a, t_stack **b,\
						int *test, int operation);
void				size_run_operation(t_stack **a, t_stack **b, int opt);

/*
**	sorting_utils.c
*/
void				rotate_a_to_put(t_stack **a, t_stack **b, t_res **res);
int					get_largest(t_stack *stack);
int					get_smallest(t_stack *stack);
int					get_index_order(t_stack *new, int index);

/*
**	result.c
*/
int					count_operation_final(t_res *operation);
void				add_operation(t_res **stack, int operation);
t_res				*init_operation(int operation);
t_res				*operation_last(t_res *stack);

/*
**	set_stack.c
*/
int					get_next_line(char **line);
char				*gnl_join(char *line, char buff);
void				set_num(int max, char **num, t_stack **stack);
void				set_index(t_stack *stack);

/*
**	markup.c
*/
void				set_markup(t_stack *stack);
void				set_tag(t_stack *new, int *tag);
int					count_markup(t_stack *stack);
int					set_headmark(t_stack *a);
void				set_headmark2(t_stack *a, t_stack *start,\
						t_stack *new, int *idx);

/*
**	operation.c
*/
int					check_order(t_stack *stack);
void				ft_swap(t_stack **a, t_stack **b, int tag);
void				ft_push(t_stack **a, t_stack **b, int tag);
void				ft_rotate(t_stack **a, t_stack **b, int tag);
void				ft_rev_rotate(t_stack **a, t_stack **b, int tag);

/*
**	stack.c
*/
void				push(t_stack **stack, t_stack *new);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
t_stack				*pop(t_stack **stack);

/*
**	stack_utils.c
*/
t_stack				*stack_init(int content);
t_stack				*stack_last(t_stack *stack);
int					stack_size(t_stack *stack);
void				stack_add_front(t_stack **stack, t_stack *new);
void				stack_add_back(t_stack **stack, t_stack *new);
void				stack_delete(t_stack **stack);

/*
**	error.c
*/
void				check_dup_error(t_stack *a);
void				exit_with_error(int errno);
int					is_string_digit(char *str);

/*
**	other_utils.c
*/
void				swap_arr(int arr[], int a_idx, int b_idx);
int					is_largest_size(t_stack **a, t_stack **b, t_res **res);
int					is_smallest_size(t_stack **a, t_stack **b, t_res **res);
int					get_gap(int a, int b);

/*
**	free.c
*/
void				stack_delete(t_stack **stack);
void				refactoring_res(t_res *res);
void				refactoring_res2(t_res *cmp, t_res *new);

/*
**	size_utils.c
*/
t_stack				*start_with_headmark(int headmark, t_stack *a);
void				init_stack_isa(t_stack *a);
void				quicksort(int arr[], int start, int end);

/*
**	print_stack.c
*/
void				print_stack(t_stack *a, t_stack *b);
void				print_stack_index(t_stack *a, t_stack *b);
void				print_operation(t_res *stack);
void				print_by_num(t_res *new);

#endif
