/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 20:33:10 by sjones            #+#    #+#             */
/*   Updated: 2017/01/29 14:40:19 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*t;
	char	*t2;

	if (s != NULL)
	{
		if (!(t = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		t2 = (char*)s;
		t[ft_strlen(s)] = '\0';
		if (s != NULL)
		{
			while (*t2)
				*t++ = f(*t2++);
			return (t - ft_strlen(s));
		}
	}
	return (NULL);
}
