/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:42:09 by cscelfo           #+#    #+#             */
/*   Updated: 2023/05/01 15:42:10 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fl_header/ft_first_layer.h"

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}
