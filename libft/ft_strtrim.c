/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:48:51 by sjones            #+#    #+#             */
/*   Updated: 2017/01/17 14:10:44 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*t1;
	char	*t2;
	int		l;

	if (s != NULL)
	{
		l = 0;
		t1 = (char*)s;
		while ((*t1 == ' ') || (*t1 == '\n') || (*t1 == '\t'))
			t1++;
		t2 = t1;
		t1 += (ft_strlen(t2) - 1);
		while (((*t1 == ' ') || (*t1 == '\n') || (*t1 == '\t'))\
				&& (l < (int)ft_strlen(t2)))
		{
			t1--;
			l++;
		}
		return (ft_strndup(t2, (ft_strlen(t2) - l)));
	}
	return (NULL);
}
