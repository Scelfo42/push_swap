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

int	ft_best_combination(int	a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (ft_take_max(a, b));
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}

int	ft_fabs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}
