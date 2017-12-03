/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:47:34 by sjones            #+#    #+#             */
/*   Updated: 2017/01/18 22:09:08 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		while ((*alst)->next)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = (*alst)->next;
		}
		if ((*alst)->next == NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
		}
		*alst = NULL;
	}
}
