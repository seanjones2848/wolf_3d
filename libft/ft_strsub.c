/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:33:20 by sjones            #+#    #+#             */
/*   Updated: 2017/01/11 14:49:59 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	char	*t;

	if (s != NULL)
	{
		if (!(r = ft_strnew(len)))
			return (NULL);
		t = (char *)s;
		t += start;
		r = ft_strncpy(r, t, len);
		return (r);
	}
	return (NULL);
}
