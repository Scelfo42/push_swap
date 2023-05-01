/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:30:08 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:31:44 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

int	*ft_stack_to_arr(t_node *stack_top, int stack_size)
{
	int	*arr;
	int	i;

	arr = (int *)ft_calloc(stack_size, sizeof(int));
	i = 0;
	while (stack_top)
	{
		arr[i++] = stack_top->data;
		stack_top = stack_top->next;
	}
	return (arr);
}

bool	ft_search_better(t_lis *lis, int *tmp_lis, int breakpoint, int index)
{
	int	interested;
	int	tmp_index;

	interested = lis->stack_arr[breakpoint];
	if (interested > lis->array[index] && lis->array[index] != 0)
		return (true);
	while (breakpoint-- > 0)
	{
		tmp_index = index;
		if ((tmp_lis[breakpoint] == index)
			&& (lis->stack_arr[breakpoint] > interested))
		{
			while ((lis->stack_arr[breakpoint] < lis->array[tmp_index])
				&& (tmp_index < lis->len))
				tmp_index++;
			if (tmp_index == lis->len)
				return (true);
			else
				break ;
		}
	}
	return (false);
}

int	*ft_clean_lis_array(t_lis *lis, int *tmp_lis, int stack_size)
{
	int	index;

	lis->array = ft_calloc(lis->len, sizeof(int));
	index = lis->len;
	while (stack_size-- > 0)
	{
		if (tmp_lis[stack_size] == index)
		{
			if (ft_search_better(lis, tmp_lis, stack_size, index) == false)
				lis->array[--index] = lis->stack_arr[stack_size];
		}
	}
	return (lis->array);
}
