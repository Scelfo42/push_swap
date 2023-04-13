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

	new_node = ft_malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*ft_destroy_node(t_stack **a, t_stack **b, char c)
{
	t_node	*tmp;

	tmp = NULL;
	if (c == 'a')
	{
		tmp = (*a)->top->prev;
		free(tmp);
		tmp = NULL;
		(*a)->top->prev = NULL;
	}
	else if (c == 'b')
	{
		tmp = (*b)->top;
		if ((*b)->size != 0)
			tmp = (*b)->top->prev;
		free(tmp);
		tmp = NULL;
		if ((*b)->size != 0)
			(*b)->top->prev = NULL;
	}
	return (tmp);
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

void	ft_add_after(t_stack **a, t_node *new_node)
{
	t_node	*last;

	if (new_node)
	{
		if ((*a)->top)
		{
			last = ft_last_node((*a)->top);
			last->next = new_node;
			new_node->prev = last;
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
	ft_check_duplicates(a, new_argv, flag);
}
