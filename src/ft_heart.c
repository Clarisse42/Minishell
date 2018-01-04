/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 08:39:06 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 15:16:56 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_heart_prog1(char **av)
{
	if (!ft_strcmp(*av, "env"))
	{
		ft_env();
		return (1);
	}
	else if (!ft_strcmp(*av, "exit"))
	{
		ft_free_array(g_environ);
		exit(0);
	}
	else if (!ft_strcmp(*av, "echo"))
	{
		ft_echo(av);
		return (1);
	}
	else if (!ft_strcmp(*av, "setenv"))
		return (cmd_setenv(av));
	else if (!ft_strcmp(*av, "unsetenv"))
		return (cmd_unsetenv(av));
	else if (!ft_strcmp(*av, "cd"))
		return (ft_cd(av));
	else
		return (-1);
}

void			ft_heart_prog2(char **av)
{
	if (av == NULL || *av == NULL)
		return ;
	if (ft_heart_prog1(av) == -1 && ft_get_path2(av, NULL, NULL, NULL) == 1)
	{
		ft_putstr("Minishell : command not found : ");
		ft_putendl(*av);
	}
}
