/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:24 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/13 11:16:09 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_sort(t_stack **a, char **new_argv, bool flag, t_stack **b)
{
	if (ft_check_order(a, true) == true)
	{
		ft_stack_print(*a, (*a)->size);
		//ft_free_world(a, new_argv, flag);
		exit(0);
	}
	(*b)->size = 0;
	if ((*a)->size == 2)
		ft_swap(a, 'a');
	else if ((*a)->size == 3)
		ft_stack3(a);
	else if ((*a)->size == 5)
	 	ft_stack5(a, b);
	ft_stack_print(*a, (*a)->size);
	ft_free_world(a, new_argv, flag);
}
