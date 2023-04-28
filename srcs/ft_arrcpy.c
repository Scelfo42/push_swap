#include "../header/ft_push_swap.h"

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
