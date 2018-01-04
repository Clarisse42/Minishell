/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 18:47:50 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/11 18:25:20 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_echo(char **av)
{
	int			line;

	line = 1;
	if (av == NULL)
		return ;
	av++;
	if (av && *av && **av == '-' && *(*av + 1) == 'n' && !*(*av + 2))
	{
		line = 0;
		av++;
	}
	while (*av)
	{
		write(1, *av, ft_strlen(*av));
		write(1, " ", 1);
		av++;
	}
	if (line)
		write(1, "\n", 1);
}
