/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:43:29 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/05 19:36:16 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

t_node	ft_create_node(t_stack *a, char **argv, int i)
{
	if (!a->head)
	{
		a->head = malloc(sizeof(t_node));
		a->head->data = ft_atol(argv[i]);
		a->head->next = NULL;
	//	a->head->prev = NULL; LOGICA
	}
	else
	{
		a->tmp = a->head;
		while (a->tmp->next != NULL)
			a-tmp = a->tmp->next;
		a->tmp = malloc(sizeof(t_node));
		a->tmp->data = ft_atol(argv[i]);
		a->tmp->next = NULL;
	}
	return; //non lo so
}

void	ft_lets_sort(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	i = 1;
	/*if (argc == 2)
	roba dello split*/
	else
	{
		while (i < argc)
		{
			ft_create_node(a, argv, i);
			i++;
		}
	}
	return; //non lo so
}
