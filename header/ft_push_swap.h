/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:17:47 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:26:33 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../projects/fl_header/ft_first_layer.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef struct s_lis
{
	long int	*array;
	int	len;
	int	index;
	int	*stack_arr;
	int	*mov_a;
	int	*mov_b;
	int	*combination;
}	t_lis;

/* ERROR MESSAGE */
void	ft_error_message(char **argv, bool flag);
/* CHECKS */
void	ft_check_errors(int new_argc, char **argv, bool flag);
void	ft_check_duplicates(t_stack **a, t_stack **b, char **new_argv, bool f);
bool	ft_check_order(t_stack *a);
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
void	ft_stack3(t_stack **stack);
void	ft_stack_any(t_stack **a, t_stack **b);
void	ft_stack_big(t_stack **a, t_stack **b);
/* UTILS */
int		ft_smallest(t_node *top);
int		ft_biggest(t_node *top);
int		ft_find_pos_min(t_node *top, int *min);
/* STACK OPERATIONS */
void	ft_swap(t_stack **ab, char stack_name, bool if_print);
void	ft_push(t_stack **from, t_stack **to, char stack_to_name, bool flag);
void	ft_rotate(t_stack **ab, char stack_name, bool if_print);
void	ft_reverse_rotate(t_stack **ab, char stack_name, bool if_print);
/* DOUBLE MOVES */
void	ss(t_stack **a, t_stack **b, bool flag);
void	rr(t_stack **a, t_stack **b, bool flag);
void	rrr(t_stack **a, t_stack **b, bool flag);
/* FREE MEMORY */
void	ft_free_argv(char **argv);
void	ft_free_stack(t_stack **stack);
void	ft_free_world(t_stack **a, t_stack **b, char **new_argv, bool flag);
/* LIS */
void	ft_lis_selection(t_stack **a, t_stack **b, t_lis *lis);
void	ft_go_back_min(t_stack **a);
long int	*ft_lis(t_lis *lis, int stack_size);
/* LIS UTILS */
int		*ft_stack_to_arr(t_node *top, int stack_size);
bool	ft_search_best_lis(t_lis *lis, int *tmp_lis, int breakpoint, int index);
long int		*ft_clean_lis_array(t_lis *lis, int *tmp_lis, int stack_size);
/* ALGORITHM */
int		ft_search_for_better(t_lis *lis, int stack_size, int pos);
int		ft_best_combination_deco(t_lis *lis, int b_size);
int		ft_do_if_possible(int a_i, int b_i, t_stack **a, t_stack **b);
int		ft_best_move(t_stack **a, t_stack **b, t_lis *lis);
void	ft_algo(t_stack **a, t_stack **b, t_lis *lis);
/* ALGORITHM UTILS */
int		ft_take_min(int first, int second);
int		ft_take_max(int first, int second);
int		ft_best_combination(int a, int b);
/* MOV_ARR_POPULATORS */
int		ft_mov_b_populate(int stack_size, int pos);
int		ft_mov_a_populate(t_node *top, int b_content, int a_size);

#endif
