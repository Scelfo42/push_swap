/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:24 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/11 14:00:43 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_sort(t_stack **a)//, t_stack **b)
{
	if (ft_check_order(a) == true)
	{
		//ft_stack_print(*a, (*a)->size);
		ft_free_stack(a);
		exit(0);
	}
	if ((*a)->size == 2)
		sa(a);
	else if ((*a)->size == 3)
		ft_stack3(a);
	//ft_stack_print(*a, (*a)->size);
	ft_free_stack(a);
}
