/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:29 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/10 12:23:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

bool	ft_check_order(t_stack *a)
{
	t_node	*previous;
	t_node	*following;

	previous = a->top;
	following = a->top->next;
	while (following)
	{
		if (previous->data > following->data) //se trova il successivo maggiore, non è in ordine
			return (false);
		previous = following; //scorri
		following = following->next; //scorri
	}
	ft_printf("Stack already correctly ordered\n");
	return (true);
}

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

void	ft_add_after(t_stack *a, t_node *new_node)
{
	t_node	*last;

	if (new_node)
	{
		if (a->top)
		{
			last = ft_last_node(a->top);
			last->next = new_node;
			new_node->prev = last;
			a->bottom = new_node;
		}
		else
		{
			a->top = new_node;
			a->bottom = a->top;
		}
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
		ft_add_after(a, ft_init_node(ft_atoi(argv[i])));
		a->size++;
		i++;
	}
	ft_check_duplicates(a->top);
	if (ft_check_order(a) == true)
		exit(0);
//	ft_checksize();
}