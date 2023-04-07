/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:29 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/07 16:24:04 by cscelfo          ###   ########.fr       */
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

void	ft_add_after(t_node **top, t_node *new_node)
{
	t_node	*last;

	if (top && new_node)
	{
		if (*top)
		{
			last = ft_last_node(*top);
			last->next = new_node;
		}
		else
			*top = new_node;
	}
}

void	ft_populate(t_stack *a, int argc, char **argv, bool f_split)
{
	int	i;

	if (f_split == true)
		i = 0;
	else
		i = 1;
	while (i < argc)
	{
		ft_add_after(&(a->top), ft_init_node(ft_atoi(argv[i])));
		i++;
	}
	ft_check_duplicates(a->top);
}
