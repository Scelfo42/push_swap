/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:24:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/11 14:41:58 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_stack_print(t_stack *a, int argc)
{
	t_node	*forward;
	t_node	*reverse;
	int	i = 1;
	int	end = argc;

	forward = a->top;
	reverse = a->bottom;
	while (forward)
	{
		ft_printf("\nnodo %d forward: [%d]\n\n", i, forward->data);
		forward = forward->next;
		i++;
	}
	while (reverse)
	{
		ft_printf("\nnodo %d reverse: [%d]\n\n", end, reverse->data);
		reverse = reverse->prev;
		end--;
	}
}

void	ft_free_stack(t_stack **a)//, t_stack **b)
{
	while ((*a)->top->next)
	{
		(*a)->top = (*a)->top->next;
		free((*a)->top->prev);
		(*a)->top->prev = NULL;
	}
	free((*a)->top);
	(*a)->top = NULL;
	free(*a);
	*a = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		new_argc;

	if (argc == 1)
		return (0);
	new_argc = ft_select_args(argc, &argv);
	ft_check_errors(new_argc, argv);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		return (0);
	ft_populate(&a, new_argc, argv);
	ft_sort(&a);//, &b);
	ft_stack_print(a, new_argc);
	return (0);
}
