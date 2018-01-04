/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 00:31:37 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/21 23:00:26 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	z = 0;
	while (to_find[y])
		y++;
	if (y == 0)
		return (str);
	while (str[x])
	{
		while (to_find[z] == str[x + z])
		{
			if (z == y - 1)
				return (str + x);
			z++;
		}
		z = 0;
		x++;
	}
	return (0);
}
