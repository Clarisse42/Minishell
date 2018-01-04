/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 02:54:45 by ccharuel          #+#    #+#             */
/*   Updated: 2017/09/03 21:15:03 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			env_expand(const int count)
{
	char			**ptr;
	char			**new;
	int				x;

	x = 0;
	new = malloc(sizeof(char*) * env_count(count + 1));
	ptr = new;
	if (!g_environ || !new)
	{
		if (new)
			free(new);
		return ;
	}
	while (g_environ[x])
	{
		*ptr++ = g_environ[x];
		x++;
	}
	*ptr = NULL;
	free(g_environ);
	g_environ = new;
}

static void			env_set(const char *key, const char *data)
{
	char			**ptr;
	size_t			nb;

	ptr = g_environ;
	if (!ptr)
		return ;
	while (*ptr)
	{
		if (compare(*ptr, key))
		{
			free(*ptr);
			*ptr = ft_strjoin(key, data);
			return ;
		}
		ptr++;
	}
	env_expand(1);
	nb = env_count(1);
	g_environ[nb] = ft_strjoin(key, data);
	g_environ[nb + 1] = NULL;
}

static int			ft_cd_home(void)
{
	if (chdir(env_get("HOME=")))
	{
		write(1, "cd : $HOME required.\n", sizeof("cd : $HOME required.\n"));
		return (1);
	}
	return (0);
}

static int			cd_move(const char *dst)
{
	if (chdir(dst))
	{
		write(1, "cd : No such file or directory.\n",
				sizeof("cd : No such file or directory.\n"));
		return (1);
	}
	return (0);
}

int					ft_cd(char **av)
{
	char			buffer[8096];
	int				status;

	if (!av)
		return (1);
	av++;
	if (*av)
	{
		if (**av == '~')
			status = ft_cd_home();
		else if (**av == '-')
			status = cd_move(env_get("OLDPWD="));
		else
			status = cd_move(*av);
	}
	else
		status = ft_cd_home();
	env_set("OLDPWD=", env_get("PWD="));
	env_set("PWD=", getcwd(buffer, 8096));
	return (status);
}
