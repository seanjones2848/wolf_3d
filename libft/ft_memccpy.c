/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:30:24 by sjones            #+#    #+#             */
/*   Updated: 2017/01/25 20:51:08 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*s;
	unsigned char	*d;

	s = (char*)src;
	d = dst;
	while (n-- > 0)
	{
		*d++ = *s++;
		if (*(d - 1) == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
