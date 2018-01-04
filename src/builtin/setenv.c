/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:21:23 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 16:55:27 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**g_environ;

static char		**ft_setenv(char *name, char *value, char *tmp, char **tab)
{
	int			x;
	int			len;
	char		*record;

	len = ft_strlen(name) + ft_strlen(value) + 2;
	record = (char*)ft_memalloc(sizeof(char) * len);
	tmp = record;
	if (record != NULL)
	{
		ft_strcpy(record, name);
		ft_strcat(record, "=");
		ft_strcat(record, value);
		if ((x = ft_getenv(name)) >= 0)
		{
			free(g_environ[x]);
			g_environ[x] = record;
		}
		else
		{
			tab = ft_add_array(record, g_environ);
			free(g_environ);
			return (tab);
		}
	}
	return (g_environ);
}

int				cmd_setenv(char **av)
{
	int			len;

	len = ft_array_len(av);
	if (len == 1)
		ft_putstr("setenv: Too few arguments\n");
	else if (len > 3)
		ft_putstr("setenv: Too many arguments\n");
	else
	{
		if (av[2] != NULL)
			g_environ = ft_setenv(av[1], av[2], NULL, NULL);
		else
			g_environ = ft_setenv(av[1], "", NULL, NULL);
	}
	return (1);
}
