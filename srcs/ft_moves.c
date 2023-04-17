/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:24:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/14 11:31:18 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_swap(t_stack **ab, char stack_name)
{
	int	tmp;

	tmp = (*ab)->top->data;
	(*ab)->top->data = (*ab)->top->next->data;
	(*ab)->top->next->data = tmp;
	if (stack_name == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	ft_rotate(t_stack **ab, char stack_name)
{
	t_node	*tmp;

	tmp = (*ab)->top;
	(*ab)->top = (*ab)->top->next;
	(*ab)->top->prev = NULL;
	(*ab)->bottom->next = tmp;
	tmp->prev = (*ab)->bottom;
	tmp->next = NULL;
	(*ab)->bottom = (*ab)->bottom->next;
	if (stack_name == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	ft_reverse_rotate(t_stack **ab, char stack_name)
{
	t_node	*tmp;

	tmp = (*ab)->bottom;
	(*ab)->bottom = (*ab)->bottom->prev;
	(*ab)->bottom->next = NULL;
	(*ab)->top->prev = tmp;
	tmp->next = (*ab)->top;
	(*ab)->top = (*ab)->top->prev;
	(*ab)->top->prev = NULL;
	if (stack_name == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	ft_push(t_stack **from, t_stack **to, char stack_to_name)
{
	t_node	*save_first;

	save_first = (*from)->top;
	(*from)->top = (*from)->top->next;
	save_first->next = NULL;
	if ((*from)->top)
		(*from)->top->prev = NULL;
	(*from)->size -= 1;
	(*to)->size += 1;
	ft_add_before(save_first, to);
	if (stack_to_name == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
