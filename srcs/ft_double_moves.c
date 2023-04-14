#include "../header/ft_push_swap.h"

void	ss(t_stack **ab)
{
	ft_swap(ab, 'a');
	ft_swap(ab, 'b');
	ft_printf("ss\n");
}

void	rr(t_stack **ab)
{
	ft_rotate(ab, 'a');
	ft_rotate(ab, 'b');
	ft_printf("rr\n");
}

void	rrr(t_stack **ab)
{
	ft_reverse_rotate(ab, 'a');
	ft_reverse_rotate(ab, 'b');
	ft_printf("rrr\n");
}