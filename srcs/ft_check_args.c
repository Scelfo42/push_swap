/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:13:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:38:00 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

bool	ft_check_order(t_stack *a)
{
	t_node	*previous;
	t_node	*following;

	if (a->size > 1)
	{
		previous = a->top;
		following = a->top->next;
		while (following)
		{
			if (previous->data > following->data)
				return (false);
			previous = following;
			following = following->next;
		}
	}
	else if (a->size == 0)
		return (false);
	return (true);
}

void	ft_check_intentions(char **argv)
{
	int	i;

	i = 0;
	if (argv && *argv)
	{
		while (argv[0][i])
		{
			if (ft_isdigit(argv[0][i]) == 0)
				ft_error_message(argv, true);
			i++;
		}
		if (ft_atol(argv[0]) > INT_MAX || ft_atol(argv[0]) < INT_MIN)
			ft_error_message(argv, true);
	}
	else
		ft_error_message(argv, true);
	return ;
}

int	ft_select_args(int argc, char **argv, char ***new_argv, bool *flag)
{
	int	check_ac;

	check_ac = argc;
	*new_argv = argv;
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		*new_argv = ft_split(*(argv + 1), ' ');
		if (!*new_argv)
			return (0);
		check_ac = ft_matlen(*new_argv);
		if (check_ac == 1)
			ft_check_intentions(*new_argv);
		*flag = true;
	}
	return (check_ac);
}
