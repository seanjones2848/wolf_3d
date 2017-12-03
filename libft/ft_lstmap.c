/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:40:51 by sjones            #+#    #+#             */
/*   Updated: 2017/01/18 23:19:16 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*t;
	t_list	*ret;

	if (!(ret = (t_list*)malloc(sizeof(lst))))
		return (NULL);
	if (lst && f)
	{
		t = f(lst);
		ret = t;
		lst = lst->next;
		while (lst)
		{
			t->next = f(lst);
			lst = lst->next;
			t = t->next;
		}
	}
	return (ret);
}
