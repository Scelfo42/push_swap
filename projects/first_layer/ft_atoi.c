/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:05:45 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/03 18:22:20 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fl_header/ft_first_layer.h"

int	ft_atoi(const char *nptr)
{
	char	*cn;
	int		result;
	int		sign;

	cn = (char *)nptr;
	result = 0;
	sign = 1;
	while ((*cn == ' ') || (*cn >= 9 && *cn <= 13))
		cn++;
	if (*cn == '-')
		sign *= -1;
	if (*cn == '-' || *cn == '+')
		cn++;
	while (*cn >= '0' && *cn <= '9')
	{
		result = (result * 10) + *cn - '0';
		cn++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	int	num1 = ft_atoi("0");
	int	num2 = ft_atoi("2147483647");
	int	num3 = ft_atoi("2147483648");
	int num4 = ft_atoi("-2147483648");
	int num5 = ft_atoi("-1");
	int num6 = ft_atoi("-1a1");
	
	ft_printf("\n\nnum1: [%d]\n\n", num1);
	ft_printf("\n\nnum2: [%d]\n\n", num2);
	ft_printf("\n\nnum3: [%d]\n\n", num3);
	ft_printf("\n\nnum4: [%d]\n\n", num4);
	ft_printf("\n\nnum5: [%d]\n\n", num5);
	ft_printf("\n\nnum6: [%d]\n\n", num6);
}*/
