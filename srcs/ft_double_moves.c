#include "../header/ft_push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a, 'a');
	ft_swap(b, 'b');
	ft_printf("ss\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, 'a');
	ft_rotate(b, 'b');
	ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, 'a');
	ft_reverse_rotate(b, 'b');
	ft_printf("rrr\n");
}
