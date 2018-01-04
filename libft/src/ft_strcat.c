/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:04:42 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/21 22:26:30 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int x;
	int y;

	y = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[y])
		y++;
	x = 0;
	while (s2[x])
	{
		s1[x + y] = s2[x];
		x++;
	}
	s1[x + y] = '\0';
	return (s1);
}
