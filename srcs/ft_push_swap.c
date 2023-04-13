/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:24:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/13 12:21:17 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		new_argc;
	char	**new_argv;
	bool	flag;

	if (argc == 1)
		return (0);
	flag = false;
	new_argc = ft_select_args(argc, argv, &new_argv, &flag);
	ft_check_errors(new_argc, new_argv, flag);
	a = ft_calloc(1, sizeof(t_stack));
	b = ft_malloc(sizeof(t_stack));
	if (!a || !b)
		return (0);
	ft_populate(&a, new_argc, new_argv, flag);
	ft_sort(&a, new_argv, flag, &b);
	return (0);
}
