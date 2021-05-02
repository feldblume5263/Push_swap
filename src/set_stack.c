/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:04:11 by junhpark          #+#    #+#             */
/*   Updated: 2021/05/02 18:40:21 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				set_index(t_stack *stack)
{
	t_stack			*temp;
	t_stack			*start;
	int				count;

	start = stack;
	while (stack)
	{
		temp = start;
		count = 0;
		while (temp)
		{
			if (temp->content < stack->content)
				count++;
			temp = temp->next;
		}
		stack->index = count;
		stack = stack->next;
	}
}

void				set_num(int max, char **num, t_stack **stack)
{
	int				idx;
	int				count;

	idx = 1;
	while (idx <= max)
	{
		if ((count = is_string_digit(num[idx])) > 0)
		{
			if (!((num[idx][0] == '+' || num[idx][0] == '-') && count == 1))
				exit_with_error(1);
		}
		stack_add_back(stack, stack_init(ft_atoi(num[idx])));
		idx++;
	}
}

char				*gnl_join(char *line, char buff)
{
	char			*ret;
	int				size;

	size = 0;
	while (line[size])
		size++;
	if (!(ret = (char *)malloc(sizeof(char) * (size + 2))))
		return (0);
	size = -1;
	while (line[++size])
		ret[size] = line[size];
	ret[size] = buff;
	ret[size + 1] = '\0';
	free(line);
	line = NULL;
	return (ret);
}

int					get_next_line(char **line)
{
	char			*buff;
	int				flag;

	buff = (char *)malloc(sizeof(char) * 2);
	if (!buff || !line || !(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	*line[0] = '\0';
	while ((flag = read(0, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			break ;
		*line = gnl_join(*line, buff[0]);
	}
	free(buff);
	buff = NULL;
	return (flag);
}
