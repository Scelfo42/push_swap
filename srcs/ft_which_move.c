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
	ft_printf("Stack already correctly ordered\n");
	return (true);
}

void	ft_stack3(t_stack *a)
{
	t_node	*first;
	t_node	*third;

	first = a->top;
	third = a->bottom;
	if (first->data > first->next->data)
	{
		if (first->data < third->data)
			ft_case1(&a);
		else
		{
			if (first->next->data > third->data)
				ft_case2(&a);
			else
				sa(&a); //temporaneo per non avere errori
				//ft_case3(&a);
		}
	}
	else
	{
		if (first->data < third->data)
			ft_case4(&a);
		else
			sa(&a); //temporaneo per non avere errori
			//ft_case5(&a);
	}
}
