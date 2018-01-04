/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:37:22 by ccharuel          #+#    #+#             */
/*   Updated: 2017/09/03 21:17:47 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				**g_environ;

static char			**ft_get_path1(char **split)
{
	char			*path;
	int				x;

	x = 0;
	while (g_environ[x] && (ft_strncmp("PATH=", g_environ[x], 5) != 0))
		x++;
	if (!g_environ[x])
		return (NULL);
	path = g_environ[x];
	split = ft_strsplit(path + 5, ':');
	return (split);
}

int					ft_without_path(char **av)
{
	char			*str;

	str = getenv("PATH");
	if (str == NULL)
	{
		if (ft_execv("", av[0], av) == 1)
			return (1);
	}
	else if (ft_execv("", av[0], av) == 1)
		return (1);
	return (0);
}

int					ft_get_path2(char **av, DIR *dir, char **split, char **tmp)
{
	struct dirent	*read;

	if (ft_without_path(av) == 1)
		return (0);
	split = ft_get_path1(NULL);
	tmp = split;
	while (split && *split && (dir = opendir(*split)))
	{
		while ((read = readdir(dir)) != NULL)
		{
			if (!(ft_strcmp(av[0], read->d_name)))
			{
				if (ft_execv(*split, *av, av) == 1)
				{
					closedir(dir);
					ft_free_array(tmp);
					return (0);
				}
			}
		}
		split++;
		closedir(dir);
	}
	ft_free_array(tmp);
	return (1);
}
