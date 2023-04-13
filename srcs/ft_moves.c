/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:24:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/10 12:24:20 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	if (a && (*a)->top)
	{
		tmp = (*a)->top->data;
		(*a)->top->data = (*a)->top->next->data;
		(*a)->top->next->data = tmp;
		ft_printf("sa\n");
	}
}

void	sb(t_stack **b)
{
	int	tmp;

	if (b && (*b)->top)
	{
		tmp = (*b)->top->data;
		(*b)->top->data = (*b)->top->next->data;
		(*b)->top->next->data = tmp;
		ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b)
{
	if ((a && (*a)->top) && (b && (*b)->top))
	{
		sa(a);
		sb(b);
		ft_printf("sb\n");
	}
}

void	pa(t_stack **a, t_stack **b)
{
	t_node	*new_node;

	new_node = ft_init_node((*b)->top->data);
	if (b && (*b)->top)
	{
		(*a)->top->prev = new_node;
		new_node->next = (*a)->top;
		(*a)->top = new_node;
		if (!(*b)->top->next)
		{
			(*b)->top = ft_destroy_node(a, b, 'b');
			ft_printf("pa\n");
			return;
		}
		(*b)->top = (*b)->top->next;
		(*b)->top->prev = ft_destroy_node(a, b, 'b');
	}
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_node	*new_node;

	new_node = ft_init_node((*a)->top->data);
	if (a && (*a)->top)
	{
		if ((*b)->top)
		{
			(*b)->top->prev = new_node;
			new_node->next = (*b)->top;
			(*b)->top = new_node;
			(*b)->bottom = ft_last_node((*b)->top);
		}
		else
		{
			(*b)->top = new_node;
			(*b)->bottom = (*b)->top;
		}
		(*a)->top = (*a)->top->next;
		(*a)->top->prev = ft_destroy_node(a, b, 'a');
	}
	ft_printf("pb\n");
}

void	ra(t_stack **a)
{
	t_node *tmp;

	if (a && (*a)->top)
	{
		tmp = (*a)->bottom;
		(*a)->bottom = (*a)->top;
		(*a)->top = (*a)->top->next;
		(*a)->bottom->prev = tmp;
		tmp->next = (*a)->bottom;
		(*a)->bottom->next = NULL;
		(*a)->top->prev = NULL;
		ft_printf("ra\n");
	}
}

void	rra(t_stack **a)
{
	t_node	*tmp;

	if (a && (*a)->top)
	{
		tmp = (*a)->top;
		(*a)->top = (*a)->bottom;
		(*a)->bottom = (*a)->bottom->prev;
		(*a)->top->next = tmp;
		tmp->prev = (*a)->top;
		(*a)->bottom->next = NULL;
		(*a)->top->prev = NULL;
    	ft_printf("rra\n");
	}
}
