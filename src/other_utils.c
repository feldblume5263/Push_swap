/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:53:51 by junhpark          #+#    #+#             */
/*   Updated: 2021/04/06 23:56:26 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				swap_arr(int arr[], int a_idx, int b_idx)
{
	int				temp;

	temp = arr[a_idx];
	arr[a_idx] = arr[b_idx];
	arr[b_idx] = temp;
}
