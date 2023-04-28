#include "../header/ft_push_swap.h"

int	ft_best_combination_deco(int *copy_a, int *copy_b, int b_size)//, int *orig_a, int *orig_b)
{
	int *comb;
	int	i;
	int	best_pos;

	comb = ft_calloc(b_size, sizeof(int));
	i = -1;
	while (++i < b_size)
		comb[i] = ft_best_combination(&copy_a, &copy_b, i);
	i = -1;
	best_pos = 0;
	while (++i < b_size)
	{
		if (comb[i] < comb[best_pos])
			best_pos = i;
	}
	free(copy_a);
	free(copy_b);
	free(comb);
	return (best_pos);
}

int	ft_do_if_convenient(int a_i, int b_i, t_stack **a, t_stack **b)
{
	while (a_i < 0 && b_i < 0)
	{
		rrr(a, b);
		a_i++;
		b_i++;
	}
	while (a_i > 0 && b_i > 0)
	{
		rr(a, b);
		a_i--;
		b_i--;
	}
	if (a_i < 0)
		while (a_i++ < 0)
			ft_reverse_rotate(a, 'a', true);
	else
		while (a_i-- > 0)
			ft_rotate(a, 'a', true);
	return (b_i);
}

int	ft_best_move(t_stack **a, t_stack **b, t_lis *lis)
{
	int		i;
	t_node	*b_tmp;

	i = -1;
	b_tmp = (*b)->top;
	lis->mov_a = ft_calloc((*b)->size, sizeof(int));
	lis->mov_b = ft_calloc((*b)->size, sizeof(int));
	while (++i < (*b)->size)
		lis->mov_b[i] = ft_mov_b_populate((*b)->size, i);
	i = -1;
	while (++i < (*b)->size && b_tmp != NULL)
	{
		lis->mov_a[i] = ft_mov_a_populate((*a)->top, b_tmp->data, (*a)->size);
		b_tmp = b_tmp->next;
	}
	i = ft_best_combination_deco(ft_arrcpy(lis->mov_a, (*b)->size), ft_arrcpy(lis->mov_b, (*b)->size), (*b)->size);//, mov_a, mov_b); test with double moves!!
	i = ft_do_if_convenient(lis->mov_a[i], lis->mov_b[i], a, b);
	free(lis->mov_a);
	free(lis->mov_b);
	return (i);
}

void	ft_algo(t_stack **a, t_stack **b, t_lis *lis)
{
	int	i;

	i = 0;
	while ((*b)->top != NULL)
	{
		i = ft_best_move(a, b, lis);
		if (i > 0)
			while (i-- > 0)
				ft_rotate(b, 'b', true);
		else
			while (i++ < 0)
				ft_reverse_rotate(b, 'b', true);
		ft_push(b, a, 'a');
	}
}
