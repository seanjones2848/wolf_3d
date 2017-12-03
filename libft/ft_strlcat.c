/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:40:18 by sjones            #+#    #+#             */
/*   Updated: 2017/01/30 14:19:07 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	int		n;
	int		l;

	s = (char*)src;
	d = dst;
	n = size;
	while (*d && n--)
		d++;
	l = d - dst;
	if (l == (int)size)
		return (size + ft_strlen(src));
	while (*s)
	{
		if (--n > 0)
			*d++ = *s;
		s++;
	}
	*d = '\0';
	return (l + (s - src));
}
