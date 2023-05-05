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

bool	ft_search_best_lis(t_lis *lis, int *tmp_lis, int breakpoint)
{
	int	interested;
	int	potential;

	interested = lis->stack_arr[breakpoint];
	if (interested < lis->last)
	{
		while (--breakpoint >= 0)
		{
			if (tmp_lis[breakpoint] == lis->index)
			{
				potential = lis->stack_arr[breakpoint];
				if (potential > interested && potential < lis->last)
					return (true);
			}
		}
		return (false);
	}
	return (true);
}

long int	*ft_clean_lis_array(t_lis *lis, int *tmp_lis, int stack_size)
{
	int size;
	int	i;

	size = stack_size;
	i = lis->len;
	lis->array = ft_calloc(lis->len + 1, sizeof(long int));
	lis->array[lis->len] = LONG_MAX;
	lis->last = LONG_MAX;
	lis->index = lis->len;
	while (size-- > 0)
	{
		if (tmp_lis[size] == lis->index)
			if (!ft_search_best_lis(lis, tmp_lis, size))
			{
				lis->array[--i] = lis->stack_arr[size];
				lis->last = lis->array[i];
				lis->index -= 1;
			}
	}
	return (lis->array);
}
