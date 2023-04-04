/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:24:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/03 17:26:30 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (!ft_check_errors(stack, argc, argv))
		return (0);
	stack->a = malloc(sizeof(t_container));
	stack->b = malloc(sizeof(t_container));
	if (!ft_stacks_exist(stack))
		return (0);
	return (0);
}
