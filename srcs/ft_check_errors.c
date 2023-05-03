/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:51:26 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:29:54 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_error_message(char **new_argv, bool flag)
{
	if (flag == true)
		ft_free_argv(new_argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_check_errors(int new_argc, char **new_argv, bool flag)
{
	int		ac_i;
	size_t	av_i;

	ac_i = 1;
	if (flag == true)
		ac_i = 0;
	av_i = 0;
	while (ac_i < new_argc && new_argv[ac_i])
	{
		av_i = 0;
		if (new_argv[ac_i][av_i] == '-' || new_argv[ac_i][av_i] == '+')
			av_i++;
		while (new_argv[ac_i][av_i])
		{
			if (ft_isdigit(new_argv[ac_i][av_i]) == 0)
				ft_error_message(new_argv, flag);
			av_i++;
		}
		if ((ft_atol(new_argv[ac_i]) > INT_MAX)
			|| (ft_atol(new_argv[ac_i]) < INT_MIN)
			|| (av_i == 0))
			ft_error_message(new_argv, flag);
		ac_i++;
	}
}

void	ft_check_duplicates(t_stack **a, t_stack **b, char **new_argv, bool f)
{
	t_node	*tmp;
	t_node	*top;

	tmp = NULL;
	top = (*a)->top;
	while (top)
	{
		tmp = top->next;
		while (tmp)
		{
			if (top->data == tmp->data)
			{
				ft_free_world(a, b, new_argv, f);
				ft_error_message(new_argv, false);
			}
			tmp = tmp->next;
		}
		top = top->next;
	}
	return ;
}
