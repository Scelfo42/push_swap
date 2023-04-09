#include "../header/ft_push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	if (a && (*a)->top)
	{
		tmp = (*a)->top->data;
		(*a)->top->data = (*a)->top->next->data;
		(*a)->top->next->data = tmp;
		ft_printf("sa\n");
	}
}

void	rra(t_stack **a)
{
	t_node	*tmp;

	if (a && (*a)->top)
	{
		tmp = (*a)->top;
		(*a)->top = (*a)->bottom;
		(*a)->bottom = (*a)->bottom->prev;
		(*a)->top->next = tmp;
		tmp->prev = (*a)->top;
		(*a)->bottom->next = NULL;
		(*a)->top->prev = NULL;
    		ft_printf("rra\n");
	}
}
