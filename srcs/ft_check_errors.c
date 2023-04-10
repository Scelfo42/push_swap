/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:51:26 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/10 11:51:10 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_error_message() //i'm the killer
{
	write(2, "Error\n", 6);
	exit(1);
}

void ft_check_errors(int argc, char **argv, bool f_split) //qui vengono controllati gli errori: (se sono cifre e non superano il max o min degli int)
{
	int	ac_i; //argc_index
	size_t	av_i; //argv_index

	if (f_split == true)
		ac_i = 0;
	else
		ac_i = 1;
	av_i = 0;
	while (ac_i < argc)
	{
		av_i = 0; //ogni volta riparte dalla prima posizione della stringa
		while (argv[ac_i][av_i]) //controllo che ogni carattere della stringa sia una cifra
		{
			if (argv[ac_i][av_i] == '-' || argv[ac_i][av_i] == '+') //se il primo carattere è un segno, lo salto e continuo
				av_i++;
			if (ft_isdigit(argv[ac_i][av_i]) == 0)
				ft_error_message(); //va a schiantarsi
			av_i++;
		}
		if (ft_atol(argv[ac_i]) > INT_MAX || ft_atol(argv[ac_i]) < INT_MIN) //controllo che ogni numero non superi max o min int
			ft_error_message(); //va a schiantarsi
		ac_i++;
	}
	return; //credo sia corretto
}

void	ft_check_duplicates(t_node *top)
{
	t_node	*tmp;
	int		flag;

	flag = 0;
	while(top)
	{
		tmp = top->next;
		while(tmp)
		{
			if (top->data == tmp->data)
				flag++;
			tmp = tmp->next;
		}
		top = top->next;
	}
	if (flag > 0)
		ft_error_message();
	return;
}
