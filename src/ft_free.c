/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:51:18 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/11 21:10:06 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_free_array(char **array)
{
	int	x;

	if (array == NULL)
		return (1);
	x = 0;
	while (array[x] != NULL)
	{
		free(array[x]);
		x++;
	}
	free(array);
	return (1);
}
