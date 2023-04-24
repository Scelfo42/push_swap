#include "../header/ft_push_swap.h"

int	*ft_stack_to_arr(t_node *top, int stack_size)
{
	int	*arr;
	int	i;

	arr = (int *)ft_calloc(stack_size, sizeof(int));
	i = 0;
	while (top)
	{
		arr[i++] = top->data;
		top = top->next;
	}
	return (arr);
}

int *ft_create_arr_lis(int *arr_stack, int *lis, int len, int size)
{
	int	*arr_lis;
	int	end;

	arr_lis = ft_calloc(len, sizeof(int));
	end = len;
	while (size-- > 0)
	{
		if (lis[size] == end)
			arr_lis[--end] = arr_stack[size];
	}
	/*while (arr_lis[end] != 0)
	{
		ft_printf("array lis[%d]: %d\n", end, arr_lis[end]);
		end++;
	}*/
	free(lis);
	return (arr_lis);
}

int	*ft_lis(int *arr_stack, int stack_size, int *len)
{
	int	*lis;
	int	i;
	int	j;

	i = 0;
	lis = ft_calloc(stack_size, sizeof(int));
	while (i < stack_size)
		lis[i++] = 1;
	i = 0;
	*len = 1;
	while (i < stack_size)
	{
		j = i + 1;
		i = 0;
		while (i < j)
		{
			if (arr_stack[i] < arr_stack[j] && lis[j] <= lis[i])
				lis[j] = 1 + lis[i];
			i++;
		}
		if (lis[j] > *len)
			*len = lis[j];
	}
/*	ft_printf("total lis: %d\n", *len);
	i = 0;
	while (lis[i] != 0)
	{
		ft_printf("array stack[%d]: %d\n", i, arr_stack[i]);
		ft_printf("array lis index[%d]: %d\n", i, lis[i]);
		i++;
	}*/
	return (ft_create_arr_lis(arr_stack, lis, *len, stack_size));
}

void	ft_lis_selection(t_stack **a, t_stack **b, int *lis, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if ((*a)->top->data == lis[i])
		{
			ft_rotate(a, 'a');
			i++;
		}
		else
			ft_push(a, b, 'b');
	}
	while ((*a)->top->data != lis[0])
		ft_push(a, b, 'b');
}

void	ft_stack_big(t_stack **a, t_stack **b)
{
	int	*arr_stack;
	int	*lis;
	int	len; //lenght of the subsequence

	i = 0;
	arr_stack = ft_stack_to_arr((*a)->top, (*a)->size);
	lis = ft_lis(arr_stack, (*a)->size, &len);
	ft_lis_selection(a, b, lis, len);
	ft_algo(a, b, lis);
}
