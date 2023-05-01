/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:35:22 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:35:42 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

int	ft_search_for_better(t_lis *lis, int stack_size, int pos)
{
	int	i;

	i = pos;
	while (++i < stack_size)
	{
		if ((lis->combination[i] == lis->combination[pos])
			&& (lis->mov_a[pos] == 0 || lis->mov_b[pos] == 0))
			if (lis->mov_a[i] != 0 && lis->mov_b[i] != 0)
				return (i);
	}
	return (pos);
}

int	ft_take_min(int first, int second)
{
	if (first > second)
		return (second);
	return (first);
}

int	ft_take_max(int first, int second)
{
	if (first < 0)
		first *= -1;
	if (second < 0)
		second *= -1;
	if (first > second)
		return (first);
	return (second);
}

int	ft_best_combination(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (ft_take_max(a, b));
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}
