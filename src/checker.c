/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:18:45 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/06 23:47:02 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;


void			pop(char item, int idx, t_stack *top)
{
	t_stack		*temp;

	if (top == NULL)
		printf("\n\n stack is Empty!\n");
	else
	{
		temp = top;
		top = top->next;
		free(temp);
	}
}

void			push(char item, t_stack *top)
{
	t_stack		*temp;

	if (!(temp = (t_stack *)malloc(sizeof(t_stack))))
		return ;
	temp->data = item;
	temp->next = top;
	top = temp;
}

int					main(int argc, char *argv[])
{
	t_stack			a;
	t_stack			b;
	int				idx;

	idx = 0;
}
