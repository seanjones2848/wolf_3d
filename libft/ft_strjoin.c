/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:50:08 by sjones            #+#    #+#             */
/*   Updated: 2017/01/25 18:39:53 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ts;
	char	*sub;

	if (s1 != NULL && s2 != NULL)
	{
		if (!(sub = ft_strnew((ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		ts = sub;
		while (*s1)
			*ts++ = *s1++;
		while (*s2)
			*ts++ = *s2++;
		return (sub);
	}
	return (NULL);
}
