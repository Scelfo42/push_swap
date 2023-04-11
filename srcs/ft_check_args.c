/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:13:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/11 14:44:25 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

bool	ft_check_order(t_stack **a)
{
	t_node	*previous;
	t_node	*following;

	previous = (*a)->top;
	following = (*a)->top->next;
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

void	ft_check_intentions(char **argv)
{
	int	i;

	i = 0;
	if (argv && *argv)
	{
		while (argv[0][i])
		{
			if (ft_isdigit(argv[0][i]) == 0)
				ft_error_message();
			i++;
		}
		if (ft_atol(argv[0]) > INT_MAX || ft_atol(argv[0]) < INT_MIN)
			ft_error_message();
	}
	ft_error_message();
}

char **ft_split_decorator(char *str, char c)
{
	char	**output;
	int		size;
	char	**bob;
	int		i;

	output = ft_split(str, c);
	size = ft_matlen(output);
	bob = ft_calloc(size + 2, sizeof(char **));
	bob[0] = " ";
	i = 1;
	while (i <= size)
	{
		bob[i] = ft_strdup(output[i - 1]);
		i++;
	}
	bob[i] = 0;
	*output = NULL;
	return (bob);
}

int	ft_select_args(int argc, char ***argv)
{
	if (argc == 2)
	{
		*argv = ft_split_decorator(*(*argv + 1), ' ');
		argc = ft_matlen(*argv);
		if (argc == 1)
			ft_check_intentions(*argv);
	}
	return (argc);
}