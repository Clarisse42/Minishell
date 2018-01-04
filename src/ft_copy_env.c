/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:35:41 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 15:01:01 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_count(void)
{
	size_t		x;
	extern char	**environ;

	x = 0;
	while (environ[x])
		x++;
	return (x);
}

char			**ft_cpy_env(void)
{
	extern char	**environ;
	char		**new_environ;
	size_t		x;
	size_t		y;

	y = ft_count();
	x = 0;
	if ((new_environ = (char**)malloc(sizeof(char*) * (y + 1))) == NULL)
		return (NULL);
	while (environ[x])
	{
		new_environ[x] = ft_strdup(environ[x]);
		x++;
	}
	new_environ[x] = NULL;
	return (new_environ);
}
