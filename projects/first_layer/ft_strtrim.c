/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:06:30 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/11 16:14:30 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fl_header/ft_first_layer.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	if (!s1 || !set)
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (start != end)
	{
		while (ft_strchr(set, s1[end]))
			end--;
		str = ft_substr(s1, start, (end - start + 1));
		return (str);
	}
	return (ft_strdup(&s1[start]));
}
/*
#include <stdio.h>
int	main()
{
	char	*s = 0;
	
}*/
