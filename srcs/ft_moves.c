/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:24:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/06 15:30:44 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_swap(t_stack **ab, char stack_name, bool if_print)
{
	int	tmp;

	if (!(*ab)->top || !(*ab)->top->next)
		return ;
	tmp = (*ab)->top->data;
	(*ab)->top->data = (*ab)->top->next->data;
	(*ab)->top->next->data = tmp;
	if (if_print)
	{
		if (stack_name == 'a')
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
}

void	ft_rotate(t_stack **ab, char stack_name, bool if_print)
{
	t_node	*tmp;

	if (!(*ab)->top || !(*ab)->top->next)
		return ;
	tmp = (*ab)->top;
	(*ab)->top = (*ab)->top->next;
	(*ab)->top->prev = NULL;
	(*ab)->bottom->next = tmp;
	tmp->prev = (*ab)->bottom;
	tmp->next = NULL;
	(*ab)->bottom = (*ab)->bottom->next;
	if (if_print)
	{
		if (stack_name == 'a')
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
}

void	ft_reverse_rotate(t_stack **ab, char stack_name, bool if_print)
{
	t_node	*tmp;

	if (!(*ab)->top || !(*ab)->top->next)
		return ;
	tmp = (*ab)->bottom;
	(*ab)->bottom = (*ab)->bottom->prev;
	(*ab)->bottom->next = NULL;
	(*ab)->top->prev = tmp;
	tmp->next = (*ab)->top;
	(*ab)->top = (*ab)->top->prev;
	(*ab)->top->prev = NULL;
	if (if_print)
	{
		if (stack_name == 'a')
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
}

void	ft_push(t_stack **from, t_stack **to, char stack_to_name, bool flag)
{
	t_node	*save_first;

	if (!(*from)->top)
		return ;
	save_first = (*from)->top;
	(*from)->top = (*from)->top->next;
	save_first->next = NULL;
	if ((*from)->top)
		(*from)->top->prev = NULL;
	else
		(*from)->bottom = NULL;
	(*from)->size -= 1;
	(*to)->size += 1;
	ft_add_before(save_first, to);
	if (flag == true)
	{
		if (stack_to_name == 'a')
			ft_printf("pa\n");
		else
			ft_printf("pb\n");
	}
}
