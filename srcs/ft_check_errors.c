/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:51:26 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/03 18:51:02 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

bool ft_stacks_exist(t_stack *stack) //controllo sul malloc degli stacks
{
	if (!stack->a || !stack->b)
	{
		write(2, "Error\n", 6);
		return (false);
	}
	return (true);
}

static bool	ft_check_parameters(int argc, char **argv)
{
//	int	i;

//	i = 1;
	if (argc == 1)
		return (false);
}

bool	ft_check_errors(t_stack *stack, int argc, char **argv) //controllo di tutti gli errori possibili
{
	else if(!ft_check_parameters(argc, argv))
		return (false);
	else if(!)
		return (false);
	else if(!)
		return (false);
	return (true);
}
