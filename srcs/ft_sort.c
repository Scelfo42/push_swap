/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:24 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:35:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_sort(t_stack **a, char **new_argv, bool flag, t_stack **b)
{
	if (ft_check_order(*a) == true)
	{
		ft_free_world(a, b, new_argv, flag);
		exit(0);
	}
	(*b)->size = 0;
	if ((*a)->size == 2)
		ft_swap(a, 'a', true);
	else if ((*a)->size == 3)
		ft_stack3(a);
	else if ((*a)->size < 10)
		ft_stack_any(a, b);
	else
		ft_stack_big(a, b);
	ft_free_world(a, b, new_argv, flag);
}
