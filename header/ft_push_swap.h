/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:17:47 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/10 11:08:28 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../projects/fl_header/ft_first_layer.h"
# include <stdio.h> //da togliere
# include <stdbool.h>

typedef struct s_node
{
    int             data;
    struct s_node   *next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

void	ft_check_errors(int argc, char **argv, bool f_split);
void	ft_error_message();
t_node	*ft_init_node(int data);
t_node	*ft_last_node(t_node *top);
void	ft_add_after(t_stack *a, t_node *new_node);
void	ft_populate(t_stack *a, int argc, char **argv, bool f_split);
void	ft_check_duplicates(t_node *top);
void	ft_stack_print(t_stack *a, int argc);
int		ft_matlen(char **argv);
bool	ft_ordered(t_stack *a);
void	ft_stack3(t_stack *a);
void	ft_case1(t_stack **a);
void	ft_case2(t_stack **a);
void	ft_case3(t_stack **a);
void	ft_case4(t_stack **a);
void	ft_case5(t_stack **a);
void	sa(t_stack **a);
void	rra(t_stack **a);
void	ra(t_stack **a);

#endif
