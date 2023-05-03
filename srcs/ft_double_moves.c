/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:42:37 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:42:38 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ss(t_stack **a, t_stack **b, bool flag)
{
	ft_swap(a, 'a', false);
	ft_swap(b, 'b', false);
	if (flag == true)
		ft_printf("ss\n");
}

void	rr(t_stack **a, t_stack **b, bool flag)
{
	ft_rotate(a, 'a', false);
	ft_rotate(b, 'b', false);
	if (flag == true)
		ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b, bool flag)
{
	ft_reverse_rotate(a, 'a', false);
	ft_reverse_rotate(b, 'b', false);
	if (flag == true)
		ft_printf("rrr\n");
}
