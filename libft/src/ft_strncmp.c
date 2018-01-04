/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 22:39:21 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/23 23:11:53 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	int x;

	x = 0;
	while (s1[x] == s2[x] && s1[x] && s2[x] && (size_t)x < n)
		x++;
	if ((size_t)x == n)
		return ((int)(unsigned char)s1[x - 1] - (int)(unsigned char)s2[x - 1]);
	return ((int)(unsigned char)s1[x] - (int)(unsigned char)s2[x]);
}
