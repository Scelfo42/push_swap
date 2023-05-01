/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_specific.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:42:31 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:42:34 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

int	ft_biggest(t_node *top)
{
	int		biggest;
	t_node	*tmp;

	biggest = 0;
	tmp = top;
	while (top)
	{
		top = top->next;
		while (top && tmp->data > top->data)
			top = top->next;
		biggest = tmp->data;
		tmp = top;
	}
	return (biggest);
}

int	ft_smallest(t_node *top)
{
	int		smallest;
	t_node	*tmp;

	smallest = 0;
	tmp = top;
	while (top)
	{
		top = top->next;
		while (top && tmp->data < top->data)
			top = top->next;
		smallest = tmp->data;
		tmp = top;
	}
	return (smallest);
}

int	ft_find_pos_min(t_node *top, int *min)
{
	int	position;

	position = 1;
	*min = ft_smallest(top);
	while (top)
	{
		if (top->data == *min)
			break ;
		top = top->next;
		position++;
	}
	return (position);
}
