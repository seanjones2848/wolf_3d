/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 21:51:58 by sjones            #+#    #+#             */
/*   Updated: 2017/01/11 15:20:02 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*t1;
	char	*t2;
	int		i;

	if (s != NULL)
	{
		i = 0;
		t2 = (char*)s;
		if (!(t1 = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		t1[ft_strlen(s)] = '\0';
		while (t2[i])
		{
			t1[i] = f(i, t2[i]);
			i++;
		}
		return (t1);
	}
	return (NULL);
}
