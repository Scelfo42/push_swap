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

bool	ft_search_best_lis(t_lis *lis, int *tmp_lis, int breakpoint, int stack_size)
{
	int	interested;
	int	potential;

	interested = lis->stack_arr[breakpoint];
	while (++breakpoint < stack_size)
	{
		if (tmp_lis[breakpoint] == lis->index)
		{
			potential = lis->stack_arr[breakpoint];
			if (potential > interested)
				return (true);
		}
	}
	return (false);
}

long int	*ft_clean_lis_array(t_lis *lis, int *tmp_lis, int stack_size)
{
	int size;
	int	i;

	size = stack_size;
	i = lis->len;
	lis->array = ft_calloc(lis->len + 1, sizeof(long int));
	lis->array[lis->len] = LONG_MAX;
	lis->index = lis->len;
	while (size > 0)
	{
		if (tmp_lis[size] == lis->index)
			if (!ft_search_best_lis(lis, tmp_lis, size, stack_size))
			{
				lis->array[--i] = lis->stack_arr[size];
				lis->index -= 1;
			}
		size--;
	}
	return (lis->array);
}
