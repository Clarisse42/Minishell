/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:21:06 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 03:47:48 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**g_environ;

char			**ft_unsetenv(char *name)
{
	int			x;
	char		**str;

	if ((x = ft_getenv(name)) >= 0)
	{
		str = ft_remove_to_array(x, g_environ);
		ft_free_array(g_environ);
		g_environ = str;
	}
	return (g_environ);
}

int				cmd_unsetenv(char **av)
{
	int			len;

	len = ft_array_len(av);
	if (len == 1)
		ft_putstr("unsetenv: Too few argument.\n");
	else if (len > 3)
		ft_putstr("unsetenv: Too many arguments.\n");
	else
		g_environ = ft_unsetenv(av[1]);
	return (1);
}
