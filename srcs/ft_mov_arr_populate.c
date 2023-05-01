/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov_arr_populate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:26:50 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:26:56 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

int	ft_min_on_top(t_node *top)
{
	int	i;
	int	min;

	i = 0;
	min = ft_smallest(top);
	while (top->data != min)
	{
		top = top->next;
		i++;
	}
	return (i);
}

bool	ft_find_smaller(int stack_data, t_node *current)
{
	t_node	*tmp;

	tmp = current->next;
	while (tmp)
	{
		if (tmp->data > stack_data && tmp->data < current->data)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

int	ft_mov_a_populate(t_node *top, int b_data, int a_size)
{
	t_node	*current;
	int		following;

	current = top;
	following = 0;
	if (b_data > ft_biggest(top))
		return (ft_mov_b_populate(a_size, ft_min_on_top(current)));
	while (current)
	{
		if (b_data < current->data)
		{
			if (ft_find_smaller(b_data, current) == false)
				break ;
		}
		current = current->next;
		following++;
	}
	return (ft_mov_b_populate(a_size, following));
}

int	ft_mov_b_populate(int stack_size, int pos)
{
	if (pos > (stack_size / 2))
		pos -= stack_size;
	return (pos);
}
