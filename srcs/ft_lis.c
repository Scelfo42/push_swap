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
	ft_printf("total lis: %d\n", *len);
	i = 0;
	while (lis[i] != 0)
	{
		ft_printf("array lis[%d]: %d\n", i, lis[i]);
		i++;
	}
	return (lis);
}

void	ft_stack_big(t_stack **a)//, t_stack **b)
{
	int	*arr_stack;
	int	*lis;
	int	len; //lenght of the subsequence

	arr_stack = ft_stack_to_arr((*a)->top, (*a)->size);
	lis = ft_lis(arr_stack, (*a)->size, &len);
}