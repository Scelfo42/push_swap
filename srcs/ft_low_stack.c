/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:23:51 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/10 12:23:53 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_stack3(t_stack **a)
{
	if ((*a)->top->data > (*a)->top->next->data)
	{
		if ((*a)->top->data < (*a)->bottom->data)
			sa(a);
		else
		{
			if ((*a)->top->next->data > (*a)->bottom->data)
			{
				sa(a);
				rra(a);
			}
			else
				ra(a);
		}
	}
	else
	{
		if ((*a)->top->data < (*a)->bottom->data)
		{
			sa(a);
			ra(a);
		}
		else
			rra(a);
	}
}

void	ft_add_middle(t_stack **a, t_stack **b, int count)
{
	if (count == 1)
	{
		ra(a);
		pa(a, b);
		rra(a);
	}
	else if (count == 2)
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
	else
		ft_error_message(NULL, false);
}

void	ft_find_pos(t_stack **a, t_stack **b)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = (*a)->top;
	if ((*b)->top->data < (*b)->top->next->data)
		sb(a);
	while ((*a)->top->data > (*b)->top->data)
	{
		pa(a, b);
		(*b)->size--;
	}
	while ((*b)->top->data > (*a)->bottom->data)
	{
		if ((*b)->size >= 2 && (*b)->top->next->data > (*a)->bottom->data)
			sb(b);
		pa(a, b);
		ra(a);
		(*b)->size--;
	}
	while (tmp && !((*b)->top->data > tmp->data && (*b)->top->data < tmp->next->data) && (*b)->size != 0)
	{
		tmp = tmp->next;
		count++;
	}
	ft_add_middle(a, b, count);
}

void	ft_stack5(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	(*b)->size += 2;
	if (ft_check_order(a, false) == true)
	{
		sb(b);
		pa(a, b);
		pa(a, b);
		(*b)->size -= 2;
		return;
	}
	ft_stack3(a);
	ft_find_pos(a, b);
}
