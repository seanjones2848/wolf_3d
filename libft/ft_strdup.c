/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:01:41 by sjones            #+#    #+#             */
/*   Updated: 2017/01/25 21:12:55 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*temp;

	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	temp = str;
	while (*s1)
		*temp++ = *s1++;
	*temp = '\0';
	return (str);
}
