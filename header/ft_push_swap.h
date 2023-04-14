/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:17:47 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/14 15:31:29 by cscelfo          ###   ########.fr       */
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

/* ERROR MESSAGE */
void	ft_error_message(char **argv, bool flag);
/* CHECKS */
void	ft_check_errors(int new_argc, char **argv, bool flag);
void	ft_check_duplicates(t_stack **a, char **new_argv, bool flag);
bool	ft_check_order(t_stack **a, bool msg);
void	ft_check_intentions(char **argv);
/* SPLIT UTILS */
int		ft_select_args(int argc, char **argv, char ***new_argv, bool *flag);
int		ft_matlen(char **argv);
/* NODE CREATION */
t_node	*ft_init_node(int data);
t_node	*ft_last_node(t_node *top);
void	ft_add_before(t_node *first_node, t_stack **to);
void	ft_add_after(t_stack **a, t_node *new_node);
void	ft_populate(t_stack **a, int new_argc, char **argv, bool flag);
/* SORT */
void	ft_sort(t_stack **a, char **new_argv, bool flag, t_stack **b);
/* LOW STACK */
void	ft_stack3(t_stack **a);
void	ft_stack5(t_stack **a, t_stack **b);
/* UTILS */
int		ft_smallest(t_stack *ab);
int		ft_biggest(t_stack *ab);
/* STACK OPERATIONS */
void	ft_swap(t_stack **ab, char stack_name);
void	ft_push(t_stack **from, t_stack **to, char stack_to_name);
void	ft_rotate(t_stack **ab, char stack_name);
void	ft_reverse_rotate(t_stack **ab, char stack_name);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
/* FREE MEMORY */
void	ft_free_argv(char **argv);
void	ft_free_stack(t_stack **a);
void	ft_free_world(t_stack **a, char **new_argv, bool flag);//, t_stack **b);
/* PRINT THE STACK */
void	ft_stack_print(t_stack *a, int argc);
void	*ft_malloc(size_t size);

#endif
