/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:33:37 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 16:45:14 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**g_environ;

static char		*ft_join_str(char *path, char *cmd)
{
	char		*new;
	char		*str;

	new = NULL;
	new = malloc(ft_strlen(path) + ft_strlen(cmd) + 2);
	if (!new || !path || !cmd)
	{
		ft_strdel(&new);
		return (NULL);
	}
	str = new;
	while (*path)
		*str++ = *path++;
	if (*(path - ((long)str - (long)new)))
		*str++ = '/';
	while (*cmd)
		*str++ = *cmd++;
	*str = 0;
	return (new);
}

int				ft_execv(char *path, char *cmd, char **av)
{
	pid_t		pid;
	char		*bin;
	int			status;

	bin = ft_join_str(path, cmd);
	if (access(bin, X_OK) != -1)
	{
		pid = fork();
		if (pid == 0)
			execve(bin, av, g_environ);
		else
		{
			waitpid(pid, &status, 0);
			ft_strdel(&bin);
			return (1);
		}
	}
	ft_strdel(&bin);
	return (0);
}
