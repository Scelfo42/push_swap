/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:51:26 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/13 12:23:21 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_error_message(char **new_argv, bool flag) //i'm the killer
{
	if (flag == true)
		ft_free_argv(new_argv);
	write(2, "Error\n", 6);
	exit(1);
}

void ft_check_errors(int new_argc, char **new_argv, bool flag) //qui vengono controllati gli errori: (se sono cifre e non superano il max o min degli int)
{
	int		ac_i; //argc_index
	size_t	av_i; //argv_index

//	if (!new_argv || !*new_argv)
//		ft_error_message(new_argv);
	ac_i = 1;
	if (flag == true)
		ac_i = 0;
	av_i = 0;
	while (ac_i < new_argc && new_argv[ac_i])
	{
		av_i = 0; //ogni volta riparte dalla prima posizione della stringa
		while (new_argv[ac_i][av_i]) //controllo che ogni carattere della stringa sia una cifra
		{
			if (new_argv[ac_i][av_i] == '-' || new_argv[ac_i][av_i] == '+') //se il primo carattere è un segno, lo salto e continuo
				av_i++;
			if (ft_isdigit(new_argv[ac_i][av_i]) == 0)
				ft_error_message(new_argv, flag);
			av_i++;
		}
		if (ft_atol(new_argv[ac_i]) > INT_MAX || ft_atol(new_argv[ac_i]) < INT_MIN || av_i == 0) //controllo che ogni numero non superi max o min int
			ft_error_message(new_argv, flag);
		ac_i++;
	}
}

void	ft_check_duplicates(t_stack **a, char **new_argv, bool flag)
{
	t_node	*tmp;
	t_node	*top;

	tmp = NULL;
	top = (*a)->top;
	while(top)
	{
		tmp = top->next;
		while(tmp)
		{
			if (top->data == tmp->data)
			{
				ft_free_world(a, new_argv, flag);
				ft_error_message(new_argv, false);
			}
			tmp = tmp->next;
		}
		top = top->next;
	}
	return;
}
