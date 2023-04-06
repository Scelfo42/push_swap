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

static void	splittamo()
{
	write(1, "ao\n", 3);
	return ;
}

void	ft_create_node(t_stack *a, int argc, char **argv)
{
	int	i;
	
	i = 1;
	while (i < argc)
	{
		if (!a->head)
		{
			a->head = malloc(sizeof(t_node));
			a->head->data = ft_atol(argv[i]);
			a->head->next = NULL;
		//	a->head->prev = NULL; LOGICA
		}
	}
	else
	{
		a->tmp = a->head;
		while (a->tmp->next != NULL)
			a->tmp = a->tmp->next;
		a->tmp = malloc(sizeof(t_node));
		a->tmp->data = ft_atol(argv[i]);
		a->tmp->next = NULL;
	}
	return (a->head); //non lo so
}
/*
void	ft_lets_sort(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
		splittamo();
	else
	{
		while (i < argc)
		{
			ft_create_node(a, argv, i);
			i++;
		}
	}
	b->head = NULL;
	return; //non lo so
}*/
