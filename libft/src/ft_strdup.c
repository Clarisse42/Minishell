/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:03:05 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 05:22:38 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		x;
	int		y;
	char	*str;

	y = 0;
	while (s1[y])
		y++;
	str = (char*)malloc(sizeof(char) * (y + 1));
	if (str == NULL)
		return (NULL);
	x = 0;
	while (x < y)
	{
		str[x] = s1[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
