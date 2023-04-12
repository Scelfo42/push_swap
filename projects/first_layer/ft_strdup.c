/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:44:52 by cscelfo           #+#    #+#             */
/*   Updated: 2022/11/17 19:25:14 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fl_header/ft_first_layer.h"

char	*ft_strdup(char *s)
{
	char	*new_s;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	new_s = (char *)ft_malloc(sizeof(char) * s_len);
	if (!new_s)
		return (NULL);
	ft_memcpy(new_s, s, s_len);
	if (!*new_s)
		ft_free_char(&new_s);
	return (new_s);
}
/*
#include <stdio.h>
int	main()
{
	char	*s = NULL;
	printf("%s\n", ft_strdup(s));
	free(s);
}*/
