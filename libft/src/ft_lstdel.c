/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:23:10 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/25 21:18:20 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *new;

	new = (*alst)->next;
	if (new != NULL)
		ft_lstdel(&new, del);
	del((*alst)->content, (*alst)->content_size);
	free((*alst));
	(*alst) = NULL;
}
