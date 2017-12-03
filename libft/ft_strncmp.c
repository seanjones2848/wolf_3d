/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:36:33 by sjones            #+#    #+#             */
/*   Updated: 2017/01/29 14:36:52 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	while (*t1 && *t2 && (n > 0))
	{
		if ((*t1 != *t2))
			return ((int)(*t1 - *t2));
		if (*t1 == *t2 && (n > 0))
			n--;
		t1++;
		t2++;
	}
	if (n)
		return ((int)(*t1 - *t2));
	if ((n == 0) || ((*t1 == '\0') && (*t2 == '\0')))
		return (0);
	return (0);
}
