/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:29 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/13 11:01:09 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

t_node	*ft_init_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*ft_last_node(t_node *top)
{
	if (top && top->next)
	{
		while (top->next)
			top = top->next;
	}
	return (top);
}

void	ft_add_before(t_node *first_node, t_stack **to)
{
	if (first_node)
	{
		if ((*to)->top)
		{
			(*to)->top->prev = first_node;
			first_node->next = (*to)->top;
			(*to)->top = (*to)->top->prev;
		}
		else
		{
			(*to)->top = first_node;
			(*to)->bottom = (*to)->top;
		}
	}
}

void	ft_add_after(t_stack **a, t_node *new_node)
{
	if (new_node)
	{
		if ((*a)->top)
		{
			(*a)->bottom->next = new_node;
			new_node->prev = (*a)->bottom;
			(*a)->bottom = new_node;
		}
		else
		{
			(*a)->top = new_node;
			(*a)->bottom = (*a)->top;
		}
	}
}

void	ft_populate(t_stack **a, int new_argc, char **new_argv, bool flag)
{
	int	i;

	i = 1;
	if (flag == true)
		i = 0;
	while (i < new_argc && new_argv[i])
	{
		ft_add_after(a, ft_init_node(ft_atoi(new_argv[i])));
		(*a)->size++;
		i++;
	}
}
