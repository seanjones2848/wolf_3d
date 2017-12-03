/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:43:45 by sjones            #+#    #+#             */
/*   Updated: 2017/01/29 14:34:40 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *lil)
{
	char	*b;
	char	*l;
	char	*t;

	b = (char*)big;
	l = (char*)lil;
	t = b;
	if (!(*l))
		return (b);
	while (*b && (ft_strlen(big) >= ft_strlen(lil)))
	{
		if (!(b = ft_strchr(b, l[0])))
			return (NULL);
		t = b;
		while (*t == *l)
		{
			l++;
			if (*l == '\0')
				return (b);
			t++;
		}
		b++;
		l = (char*)lil;
	}
	return (NULL);
}
