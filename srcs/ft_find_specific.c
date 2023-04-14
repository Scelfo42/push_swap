#include "../header/ft_push_swap.h"

int	ft_biggest(t_stack *ab)
{
	int		biggest;
	t_node	*tmp;

	biggest = 0;
	tmp = ab->top;
	while (ab->top)
	{
		ab->top = ab->top->next;
		while (ab->top && tmp->data > ab->top->data)
			ab->top = ab->top->next;
		biggest = tmp->data;
		tmp = ab->top;
	}
	return (biggest);
}

int	ft_smallest(t_stack *ab)
{
	int		smallest;
	t_node	*tmp;

	smallest = 0;
	tmp = ab->top;
	while (ab->top)
	{
		ab->top = ab->top->next;
		while (ab->top && tmp->data < ab->top->data)
			ab->top = ab->top->next;
		smallest = tmp->data;
		tmp = ab->top;
	}
	return (smallest);
}
