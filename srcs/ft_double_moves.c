#include "../header/ft_push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a, 'a', false);
	ft_swap(b, 'b', false);
	ft_printf("ss\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, 'a', false);
	ft_rotate(b, 'b', false);
	ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, 'a', false);
	ft_reverse_rotate(b, 'b', false);
	ft_printf("rrr\n");
}
