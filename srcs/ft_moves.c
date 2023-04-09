#include "../header/ft_push_swap.h"

void	sa(t_stack **a)
{
	t_node *tmp;
	
	tmp = (*a)->top;
	(*a)->top = (*a)->top->next;
	(*a)->top->next = tmp;
	(*a)->bottom->prev = tmp;
	tmp->prev = (*a)->top;
	tmp->next = (*a)->bottom;
}
/*
void	rra(t_stack **a)
{
	t_node	*tmp;
	t_node	*new_bottom;

	tmp = (*a)->top;
	new_bottom = (*a)->bottom->prev;
}*/
