/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:24:30 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/25 21:37:55 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	x;

	if ((mem = malloc(size)) == NULL)
		return (NULL);
	x = 0;
	while (x < size)
	{
		mem[x] = 0;
		x++;
	}
	return (mem);
}
