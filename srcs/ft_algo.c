#include "../header/ft_push_swap.h"

int	ft_min_on_top(t_node *top)
{
	int	i;
	t_node *tmp;

	i = 0;
	tmp = top;
	while (tmp->data != ft_smallest(top))
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

bool	ft_find_smaller(int stack_data, t_node *current)
{
	t_node	*tmp;

	tmp = current->next;
	while (tmp)
	{
		if (tmp->data > stack_data && tmp->data < current->data)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

int	ft_mov_a_populate(t_stack **a, int b_data, int a_size)
{
	t_node	*current;
	int		following;

	current = (*a)->top;
	following = 0;
	if (b_data > ft_biggest((*a)->top))
		return (ft_mov_b_populate(a_size, ft_min_on_top(current)));
	while (current)
	{
		if (b_data < current->data)
		{
			if (ft_find_smaller(b_data, current) == false)
				break ;
		}
		current = current->next;
		following++;
	}
	return (ft_mov_b_populate(a_size, following));
}

int	ft_mov_b_populate(int stack_size, int pos)
{
	if (pos > (stack_size / 2))
		pos -= stack_size;
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

int	ft_best_combination(int	**copy_a, int **copy_b, int i)
{
	if (((*copy_a)[i] > 0 && (*copy_b)[i] > 0) || ((*copy_a)[i] < 0 && (*copy_b)[i] < 0))
		return (ft_take_max((*copy_a)[i], (*copy_b)[i]));
	if ((*copy_a)[i] < 0)
		(*copy_a)[i] *= -1;
	if ((*copy_b)[i] < 0)
		(*copy_b)[i] *= -1;
	return ((*copy_a)[i] + (*copy_b)[i]);
}

int	ft_best_combination_deco(int *copy_a, int *copy_b, int b_size)
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
		/*if (comb[i] == comb[best_pos])
		{
			if (copy_a[best_pos] != 0 && copy_b[best_pos] != 0)
				continue;
			else if (copy_a[i] != 0 && copy_b[i] != 0)
				best_pos = i;
		}*/
	}
	free(copy_a);
	free(copy_b);
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

int	ft_best_move(t_stack **a, t_stack **b)
{
	int		*mov_a;
	int		*mov_b;
	int		i;
	t_node	*tmp;

	i = -1;
	tmp = (*b)->top;
	mov_a = ft_calloc((*b)->size, sizeof(int));
	mov_b = ft_calloc((*b)->size, sizeof(int));
	while (++i < (*b)->size)
		mov_b[i] = ft_mov_b_populate((*b)->size, i);
	i = -1;
	while (++i < (*b)->size && tmp != NULL)
	{
		mov_a[i] = ft_mov_a_populate(a, tmp->data, (*a)->size);
		tmp = tmp->next;
	}
	i = ft_best_combination_deco(ft_arrcpy(mov_a, (*b)->size), ft_arrcpy(mov_b, (*b)->size), (*b)->size);
	i = ft_do_if_convenient(mov_a[i], mov_b[i], a, b);
	free(mov_a);
	free(mov_b);
	return (i);
}

void	ft_algo(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while ((*b)->top != NULL)
	{
		i = ft_best_move(a, b);
		if (i > 0)
			while (i-- > 0)
				ft_rotate(b, 'b', true);
		else
			while (i++ < 0)
				ft_reverse_rotate(b, 'b', true);
		ft_push(b, a, 'a');
	}	
}
