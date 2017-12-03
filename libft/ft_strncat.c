/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:24:03 by sjones            #+#    #+#             */
/*   Updated: 2017/01/29 14:31:42 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*t1;
	int		l;
	int		m;

	t1 = s1;
	l = ft_strlen(s1);
	m = ((ft_strlen(s2) < n) ? (ft_strlen(s2)) : (n));
	ft_strncpy(&t1[l], s2, m);
	t1[(l + m)] = '\0';
	return (t1);
}
