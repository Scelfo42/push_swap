#include "../header/ft_push_swap.h"

void	ft_go_back_min(t_stack **a)
{
	t_node	*search;
	int		min;
	int		half;

	search = (*a)->top;
	min = ft_smallest((*a)->top);
	half = 0;
	while (search->data != min)
	{
		search = search->next;
		half++;
	}
	if (half > ((*a)->size / 2))
	{
		while ((*a)->top->data != min)
			ft_reverse_rotate(a, 'a', true);
	}
	else
	{
		while ((*a)->top->data != min)
			ft_rotate(a, 'a', true);
	}
}

void	ft_lis_selection(t_stack **a, t_stack **b, t_lis *lis)
{
	int	i;

	i = 0;
	while ((*a)->size > lis->len)
	{
		if ((*a)->top->data == lis->array[i])
		{
			ft_rotate(a, 'a', true);
			i++;
		}
		else
			ft_push(a, b, 'b');
	}
	while ((*a)->top->data != lis->array[0])
		ft_push(a, b, 'b');
}

int	*ft_lis(t_lis *lis, int stack_size)
{
	int	*tmp_lis;
	int	i;
	int	j;

	tmp_lis = ft_calloc(stack_size, sizeof(int));
	i = -1;
	while (++i < stack_size)
		tmp_lis[i] = 1;
	i = 0;
	lis->len = 1;
	while (i < stack_size)
	{
		j = i + 1;
		i = 0;
		while (i < j)
		{
			if (lis->stack_arr[i] < lis->stack_arr[j] && tmp_lis[j] <= tmp_lis[i])
				tmp_lis[j] = tmp_lis[i] + 1;
			i++;
		}
		if (tmp_lis[j] > lis->len && tmp_lis[j] < stack_size)
			lis->len = tmp_lis[j];
	}
	lis->array = ft_clean_lis_array(lis, tmp_lis, stack_size);
	free(tmp_lis);
	return (lis->array);
}

void	ft_stack_big(t_stack **a, t_stack **b)
{
	t_lis	*lis;

	lis = (t_lis *)malloc(sizeof(t_lis));
	lis->stack_arr = ft_stack_to_arr((*a)->top, (*a)->size);
	lis->array = ft_lis(lis, (*a)->size);
	ft_lis_selection(a, b, lis);
	ft_algo(a, b, lis);
	ft_go_back_min(a);
	free(lis->stack_arr);
	free(lis->array);
	free(lis);
}
