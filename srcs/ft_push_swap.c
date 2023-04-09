/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:24:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/07 16:26:17 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_stack_print(t_stack *a, int argc)
{
	t_node	*tmp;
	t_node	*rev;
	int	i = 1;
	int	end = argc - 1;

	tmp = a->top;
	rev = a->bottom;
	while (tmp && rev)
	{
		ft_printf("\nnodo %d tmp: [%d]\n\n", i, tmp->data);
		tmp = tmp->next;
		ft_printf("\nnodo %d rev: [%d]\n\n", end, rev->data);
		rev = rev->prev;
		i++;
		end--;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	bool    f_split;

	f_split = false;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_matlen(argv);
		f_split = true;
	}
	ft_check_errors(argc, argv, f_split);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (0);
	ft_populate(a, argc, argv, f_split);
	if (ft_ordered(a) == true)
		exit(0);
	ft_stack3(a);
	ft_stack_print(a, argc);
	return (0);
}
