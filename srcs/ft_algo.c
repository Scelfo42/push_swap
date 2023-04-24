#include "../header/ft_push_swap.h"

int	ft_find_next(t_node *somewhere, int *i)
{
	t_node	*check;
	int		j;

	check = somewhere->next;
	j = 0;
	if (check)
	{
		*i += j;
		check = somewhere->next;
		while (check && somewhere->content < check->content)
		{
			check = check->next;
			j++;
		}
		somewhere = check;
	}
	return (*i);
}

int	ft_mov_a_populate(t_stack **a, int b_content, int b_size)
{
	t_node	*tmp;
	int		i;
	int		following;

	tmp = (*a)->top;
	i = 0;
	while (tmp && b_content > tmp->content)
	{
		tmp = tmp->next;
		i++;
	}
	following = ft_find_next(tmp, &i);
	return (ft_mov_b_populate(following, b_size));
}

int	ft_mov_b_populate(t_stack **b, int pos)
{
	if (pos > ((*b)->size / 2))
		pos -= (*b)->size;
	return (pos);
}

int	*ft_arrcpy(int *arr, int size)
{
	int	*new;
	int	i;

	new = ft_calloc(size, sizeof(int));
	i = -1;
	while (++i < size)
		new[i] = arr[i];
	return (new);
}

int	ft_take_min(int first, int second)
{
	if (first > second)
		return (second);
	return (first);
}

int	ft_take_max(int first, int second)
{
	if (first < 0)
		first *= -1;
	else if (second < 0)
		second *= -1;
	if (first > second)
		return (first);
	return (second);
}

int	ft_best_combination(int	*copy_a, int *copy_b, int i)
{
	if ((*copy_a)[i] > 0 && (*copy_b)[i] > 0 || (*copy_a)[i] < 0 && (*copy_b)[i] < 0)
		return (ft_take_max((*copy_a)[i], (*copy_b)[i]));
	if ((*copy_a)[i] < 0)
		(*copy_a)[i] *= -1;
	if ((*copy_b)[i] < 0)
		(*copy_b)[i] *= -1;
	return ((*copy_a)[i] + (*copy_b)[i]);
}

int	ft_best_combination_deco(int *mov_a, int *mov_b, b_size)
{
	int	i;
	int	*copy_a;
	int	*copy_b;
	int	*comb;
	int	min_moves;

	copy_a = ft_arrcpy(mov_a, b_size);
	copy_b = ft_arrcpy(mov_b, b_size);
	comb = ft_calloc(b_size, sizeof(int));
	i = -1;
	min_moves = 0;
	while (++i < b_size)
		comb[i] = ft_best_combination(&copy_a, &copy_b, i);
	free(copy_a);
	free(copy_b);
	i = -1;
	while (++i < b_size)
		min_moves = ft_take_min(comb[i], comb[i + 1]);
	return (min_moves);
}

int	ft_best_move(t_stack **a, t_stack **b)
{
	int	*mov_a;
	int	*mov_b;
	int	i;
	t_node	*tmp;

	i = -1;
	tmp = (*b)->top;
	mov_a = ft_calloc((*b)->size, sizeof(int));
	mov_b = ft_calloc((*b)->size, sizeof(int));
	while (++i < (*b)->size)
		mov_b[i] = ft_mov_b_populate(b, i);
	i = -1;
	while (++i < (*b)->size && tmp != NULL)
	{
		mov_a[i] = ft_mov_a_populate(a, tmp->content, (*b)->size);
		tmp = tmp->next;
	}
	i = ft_best_combination_deco(mov_a, mov_b, (*b)->size);
	i = ft_do_it();
	free(mov_a);
	free(mov_b);
}

void	ft_algo(t_stack **a, t_stack **b, int *lis)
{
	int	i;

	i = 0;
	while ((*b)->top != NULL)
	{
		i = ft_best_move(a, b);
		if (i > 0)
			while (i-- > 0)
				ft_rotate(a, 'a');
		else
			while (i++ < 0)
				ft_reverse_rotate(a, 'a');
		ft_push(b, a, 'a');
	}	
}
