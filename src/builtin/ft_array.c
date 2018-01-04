/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 18:52:04 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 03:55:48 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**ft_malloc_array(char *str, char **array)
{
	int			x;
	char		**new_array;

	x = 0;
	while (array[x] != NULL)
		x++;
	new_array = (char**)malloc(sizeof(char*) * (x + 2));
	if (new_array == NULL)
		return (array);
	x = 0;
	while (array[x] != NULL)
	{
		new_array[x] = array[x];
		x++;
	}
	new_array[x] = str;
	new_array[x + 1] = NULL;
	return (new_array);
}

char			**ft_add_array(char *str, char **array)
{
	char		**new_array;

	if (array == NULL)
	{
		new_array = (char**)malloc(sizeof(char*) * 2);
		if (new_array == NULL)
			return (array);
		new_array[0] = str;
		new_array[1] = NULL;
	}
	else
		return (ft_malloc_array(str, array));
	ft_free_array(new_array);
	return (array);
}

char			**ft_cpy_array(int rem, char **new_array, char **array, int len)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (x < len)
	{
		if (x != rem)
		{
			new_array[y] = (char*)malloc(sizeof(char) *
					(ft_strlen(array[x]) + 1));
			if (new_array[y])
			{
				ft_strcpy(new_array[y], array[x]);
				y++;
			}
		}
		x++;
	}
	new_array[y] = NULL;
	return (new_array);
}

int				ft_array_len(char **array)
{
	int			x;

	if (array == NULL)
		return (0);
	x = 0;
	while (array[x] != NULL)
		x++;
	return (x);
}

char			**ft_remove_to_array(int rem, char **array)
{
	int			len;
	char		**new_array;

	new_array = NULL;
	if (array != NULL)
	{
		len = ft_array_len(array);
		new_array = (char**)malloc(sizeof(char*) * (len));
		new_array = ft_cpy_array(rem, new_array, array, len);
	}
	return (new_array);
}
