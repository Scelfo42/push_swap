/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:07:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 17:14:13 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static char	**ft_check_split(int *ac, char **av, bool *flag)
{
	char	**check_args;

	check_args = av;
	if (ft_strchr(av[1], ' '))
	{
		check_args = ft_split(av[1], ' ');
		ft_printf("ao bello sto split");
		if (!check_args)
			return (0);
		*ac = ft_matlen(check_args);
		if (*ac == 1)
			ft_check_intentions(check_args);
		*flag = true;
	}
	return (check_args);
}

static int	ft_which_move(t_stack **a, t_stack **b, char *input)
{
	if (!ft_strncmp(input, "sa\n", 3))
		ft_swap(a, 'a', false);
	else if (!ft_strncmp(input, "sb\n", 3))
		ft_swap(b, 'b', false);
	else if (!ft_strncmp(input, "ss\n", 3))
		ss(a, b, false);
	else if (!ft_strncmp(input, "pa\n", 3))
		ft_push(b, a, 'a', false);
	else if (!ft_strncmp(input, "pb\n", 3))
		ft_push(a, b, 'b', false);
	else if (!ft_strncmp(input, "ra\n", 3))
		ft_rotate(a, 'a', false);
	else if (!ft_strncmp(input, "rb\n", 3))
		ft_rotate(b, 'b', false);
	else if (!ft_strncmp(input, "rr\n", 3))
		rr(a, b, false);
	else if (!ft_strncmp(input, "rra\n", 4))
		ft_reverse_rotate(a, 'a', false);
	else if (!ft_strncmp(input, "rrb\n", 4))
		ft_reverse_rotate(b, 'b', false);
	else if (!ft_strncmp(input, "rrr\n", 4))
		rrr(a, b, false);
	else
		return (0);
	return (1);
}

static void	ft_execute_input(t_stack **a, t_stack **b)
{
	char	*input;
	int		move;

	move = 0;
	input = get_next_line_bonus(0);
	while (input)
	{
		move = ft_which_move(a, b, input);
		free(input);
		input = NULL;
		if (move == 0)
		{
			ft_error_message(NULL, false);
			break ;
		}
		input = get_next_line_bonus(0);
	}
	// ft_printf("move here is: [%d]\n\n", move);
	if ((move == 0) || (move == 1 && ft_check_order(*a)))
		ft_printf("OK\n");
	else if (!ft_check_order(*a))
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	bool	flag;

	flag = false;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		argv = ft_check_split(&argc, argv, &flag);
	if (!argv)
		return (0);
	ft_check_errors(argc, argv, flag);
	a = ft_calloc(1, sizeof(t_stack));
	b = ft_calloc(1, sizeof(t_stack));
	ft_populate(&a, argc, argv, flag);
	ft_check_duplicates(&a, &b, argv, flag);
	b->size = 0;
	ft_execute_input(&a, &b);
	ft_free_world(&a, &b, argv, flag);
	return (0);
}
