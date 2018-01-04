/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 20:34:17 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/21 23:04:23 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	x;
	int n;
	int nbr;

	x = 0;
	n = 0;
	nbr = 0;
	while ((str[x] == ' ') || (str[x] == '\n') || (str[x] == '\t') || (str[x]
				== '\v') || (str[x] == '\r') || (str[x] == '\f'))
		x++;
	if (str[x] == '-')
		n++;
	if (str[x] == '-' || str[x] == '+')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		nbr *= 10;
		nbr += (str[x] - '0');
		x++;
	}
	if (n == 1)
		return (-nbr);
	else
		return (nbr);
}
