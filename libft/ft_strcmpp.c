/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:21:38 by sjones            #+#    #+#             */
/*   Updated: 2017/01/11 13:42:47 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmpp(const char *s1, const char *s2)
{
	int		l;

	if (s1 && s2)
	{
		l = ((ft_strlen(s1) > ft_strlen(s2)) ? ft_strlen(s2) : ft_strlen(s1));
		return (ft_memcmp(s1, s2, (l + 1)));
	}
	return (0);
}
