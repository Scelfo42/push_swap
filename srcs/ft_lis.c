/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:42:45 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/02 14:01:07 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"
#include <stdio.h>

void	ft_go_back_min(t_stack **a)
{
	t_node	*search;
	int		min;
	int		half;

	search = (*a)->top;
	min = ft_smallest((*a)->top);
	half = 0;
	while (search->data != min)
	{
		search = search->next;
		half++;
	}
	if (half > ((*a)->size / 2))
	{
		while ((*a)->top->data != min)
			ft_reverse_rotate(a, 'a', true);
	}
	else
	{
		while ((*a)->top->data != min)
			ft_rotate(a, 'a', true);
	}
}

void	ft_lis_selection(t_stack **a, t_stack **b, t_lis *lis)
{
	int	i;

	i = 0;
	while (((*a)->size > lis->len))
	{
		if ((*a)->top->data == lis->array[i])
		{
			ft_rotate(a, 'a', true);
			i++;
		}
		else
			ft_push(a, b, 'b', true);
	}
}

long int	*ft_lis(t_lis *lis, int stack_size)
{
	int	*tmp_lis;
	int	i;
	int	j;

	tmp_lis = ft_calloc(stack_size, sizeof(int));
	i = -1;
	j = -1;
	while (++i < stack_size)
		tmp_lis[i] = 1;
	while (++j < stack_size)
	{
		i = j - 1;
		while (++i < stack_size)
		{
			if (lis->stack_arr[j] < lis->stack_arr[i] && tmp_lis[j] == tmp_lis[i])
			{
				tmp_lis[i] += 1;
				if (tmp_lis[i] > lis->len)
					lis->len = tmp_lis[i];
			}
		}
	}
	// i = -1;
	// while (++i < stack_size)
	// 	printf("\ntmp_lis[%d] = %d -> lis->stack_arr = %d\n\n", i, tmp_lis[i], lis->stack_arr[i]);
	lis->array = ft_clean_lis_array(lis, tmp_lis, stack_size);
	free(tmp_lis);
	// i = -1;
	// while (++i <= lis->len)
	// 	printf("\nlis->array[%d] = %ld\n\n", i, lis->array[i]);
	// ft_printf("\nlis->len = %d\n\n", lis->len);
	return (lis->array);
}

void	ft_stack_big(t_stack **a, t_stack **b)
{
	t_lis	*lis;

	lis = (t_lis *)malloc(sizeof(t_lis));
	lis->len = 1;
	lis->stack_arr = ft_stack_to_arr((*a)->top, (*a)->size);
	// if (lis->stack_arr)
	// {
	// 	int i = -1;
	// 	while (++i < (*a)->size)
	// 		printf("\narr[%d] -> %d\n", i, lis->stack_arr[i]);
	// }
	lis->array = ft_lis(lis, (*a)->size);
	ft_lis_selection(a, b, lis);
	free(lis->stack_arr);
	lis->stack_arr = NULL;
	ft_algo(a, b, lis);
	ft_go_back_min(a);
	free(lis->array);
	free(lis);
}
