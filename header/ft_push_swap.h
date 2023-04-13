/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:17:47 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/13 12:20:52 by cscelfo          ###   ########.fr       */
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
void	ft_add_after(t_stack **a, t_node *new_node);
void	ft_populate(t_stack **a, int new_argc, char **argv, bool flag);
/* TOP NODE DESTRUCTION */
t_node	*ft_destroy_node(t_stack **a, t_stack **b, char c);
/* SORT */
void	ft_sort(t_stack **a, char **new_argv, bool flag, t_stack **b);
/* LOW STACK */
void	ft_stack3(t_stack **a);
void	ft_stack5(t_stack **a, t_stack **b);
/* UTILS */
void	ft_find_pos(t_stack **a, t_stack **b);
void	ft_add_middle(t_stack **a, t_stack **b, int count);
/* STACK OPERATIONS */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
// void	rb(t_stack **b);
// void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
// void	rrb(t_stack **b);
// void	rrr(t_stack **a, t_stack **b);
/* FREE MEMORY */
void	ft_free_argv(char **argv);
void	ft_free_stack(t_stack **a);
void	ft_free_world(t_stack **a, char **new_argv, bool flag);//, t_stack **b);
/* PRINT THE STACK */
void	ft_stack_print(t_stack *a, int argc);
void	*ft_malloc(size_t size);

#endif
