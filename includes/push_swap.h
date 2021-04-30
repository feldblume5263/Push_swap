/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:54:43 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/30 16:53:41 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // 삭제 필수...!
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
int					main(int argc, char *argv[]);
void				get_operation(t_stack **a, t_stack **b);
int					run_operation(char *opt, t_stack **a, t_stack **b);

/*
**	push_swap.c
*/

int					main(int argc, char *argv[]);


/*
**	sorting_utils.c
*/
int					get_largest(t_stack *stack);
int					get_smallest(t_stack *stack);
int					get_index_order(t_stack *new, int index);

/*
**	result.c
*/
void				add_operation(t_res **stack, int operation);
t_res				*init_operation(int operation);
void				print_operation(t_res *stack);
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
void				exit_with_error(int errno);
int					is_string_digit(char *str);

/*
**	other_utils.c
*/
void				swap_arr(int arr[], int a_idx, int b_idx);

/*
**	quick_sort.c
*/
void				quicksort(int arr[], int start, int end);

/*
**	print_stack.c
*/
void				print_stack(t_stack *a, t_stack *b);
void				print_stack_with_opt(t_stack *a, t_stack *b);

#endif
