/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:17:47 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/05 19:15:54 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../projects/fl_header/ft_first_layer.h"
# include <stdio.h> //da togliere

typedef struct s_node
{
    int             data;
    struct s_node   *next;
//	struct s_node	*prev; CAPISCI
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tmp;
}	t_stack;

void	ft_check_errors(int argc, char **argv);
void	ft_error_message();
void	ft_lets_sort(t_stack *a, t_stack *b, int argc, char **argv);
t_node	ft_create_node(t_stack *a, char **argv, int i);

#endif
