/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:11:33 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/13 12:25:57 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_free_stack(t_stack **a)
{
	if ((*a)->size > 1)
	{
		while ((*a)->top->next)
		{
			(*a)->top = (*a)->top->next;
			free((*a)->top->prev);
		}
	}
	free((*a)->top);
	free(*a);
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	ft_free_world(t_stack **a, char **new_argv, bool flag)//, t_stack **b)
{
	if (*a)
		ft_free_stack(a);
	if (new_argv && flag == true)
		ft_free_argv(new_argv);
}

