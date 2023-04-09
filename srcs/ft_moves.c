#include "../header/ft_push_swap.h"

bool	ft_ordered(t_stack *a)
{
	t_node	*previous;
	t_node	*following;

	previous = a->top;
	following = a->top->next;
	while (following)
	{
		if (previous->data > following->data) //se trova il successivo maggiore, non è in ordine
			return (false);
		previous = following; //scorri
		following = following->next; //scorri
	}
	return (true);
}
/*
void	ft_moves3(t_stack **a)
{
}*/
