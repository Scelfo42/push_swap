/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:13:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/04/10 14:16:07 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_do_split(int *argc, char ***argv, bool *f_split)
{
	*argv = ft_split(*(*argv + 1), ' ');
	*argc = ft_matlen(*argv);
	*f_split = true;
}
