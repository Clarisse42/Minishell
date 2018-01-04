/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 18:58:03 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 13:54:30 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**g_environ;

int				compare(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	if (*(s1 - 1) == '=' && *(s2 - 1) == '=')
		return (1);
	return (0);
}

static size_t	ft_strlen_magik(const char *str, const char c)
{
	size_t		size;

	size = 0;
	while (str[size])
	{
		if (str[size] == c)
			return (size);
		size++;
	}
	return (size);
}

size_t			env_count(size_t base)
{
	char		**ptr;

	ptr = g_environ;
	if (!ptr)
		return (base);
	while (*ptr)
	{
		base++;
		ptr++;
	}
	return (base);
}

const char		*env_get(const char *str)
{
	char		**ptr;

	ptr = g_environ;
	if (!ptr)
		return (NULL);
	while (*ptr)
	{
		if (compare(*ptr, str))
			return (*ptr + ft_strlen_magik(*ptr, '=') + 1);
		ptr++;
	}
	return (NULL);
}

char			*copy(const char *string)
{
	char		*new;
	char		*ptr;

	new = malloc(ft_strlen(string) + 1);
	ptr = new;
	if (!new || !string)
	{
		if (new)
			free(new);
		return (NULL);
	}
	while (*string)
		*ptr++ = *string++;
	*ptr = 0;
	return (new);
}
