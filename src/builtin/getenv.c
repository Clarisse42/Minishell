/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 18:48:26 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 02:48:03 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**g_envion;

char			*my_getenv(const char *str)
{
	char		**ptr;
	size_t		len;

	len = ft_strlen(str);
	ptr = g_environ;
	if (!g_environ)
		return (NULL);
	while (*ptr)
	{
		if (!ft_strncmp(*ptr, str, len))
			return (*ptr + len + 1);
		else
			ptr++;
	}
	return (NULL);
}

int				ft_getenv(char *name)
{
	char		**ptr;
	size_t		len;

	len = ft_strlen(name);
	ptr = g_environ;
	if (!g_environ)
		return (-1);
	while (*ptr)
	{
		if (!ft_strncmp(*ptr, name, len))
			return ((int)(ptr - g_environ));
		else
			ptr++;
	}
	return (-1);
}
