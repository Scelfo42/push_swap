/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:11:33 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:34:41 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	if ((*stack)->size > 1)
	{
		while ((*stack)->top->next)
		{
			(*stack)->top = (*stack)->top->next;
			free((*stack)->top->prev);
		}
	}
	free((*stack)->top);
	free(*stack);
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	ft_free_world(t_stack **a, t_stack **b, char **new_argv, bool flag)
{
	if (a && *a)
		ft_free_stack(a);
	if (b && *b)
		ft_free_stack(b);
	if (new_argv && flag == true)
		ft_free_argv(new_argv);
}
