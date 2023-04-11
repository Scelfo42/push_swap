#include "../fl_header/ft_first_layer.h"

void	*ft_free_char(char **ptr_s)
{
	if (*ptr_s)
	{
		free(*ptr_s);
		*ptr_s = 0;
	}
	return (*ptr_s);
}

void	*ft_free_void(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
	return (*ptr);
}
/*
void	**ft_free_mat(char ***ptr_mat)
{
	if (*ptr_mat)
	{
		if (**ptr_mat)
		{
			ft_free_char(*ptr_mat);
		}
		*ptr_mat = 0;
	}
	return ((void **)*ptr_mat);
}*/