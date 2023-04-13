/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:05:50 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/13 15:50:42 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_stack_print(t_stack *a, int argc)
{
	t_node	*forward = a->top;
	t_node	*reverse = a->bottom;
	int	i = 1;
	int	end = argc;

	while (forward)
	{
		ft_printf("\nnodo %d forward: [%d]\n\n", i, forward->data);
		forward = forward->next;
		i++;
	}
	while (reverse)
	{
		ft_printf("\nnodo %d reverse: [%d]\n\n", end, reverse->data);
		reverse = reverse->prev;
		end--;
	}
}
