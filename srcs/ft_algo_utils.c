#include "../header/ft_push_swap.h"

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
	if (second < 0)
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
