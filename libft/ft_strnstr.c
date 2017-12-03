/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:43:45 by sjones            #+#    #+#             */
/*   Updated: 2017/01/29 14:48:06 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	if (!(*lil))
		return ((char*)big);
	while (big[i] && len)
	{
		n = 0;
		j = i;
		while ((big[j] == lil[n]) && big[j++] && (n++ < len))
		{
			if (!(lil[n]))
				return ((char*)(big + i));
		}
		i++;
		len--;
	}
	return (NULL);
}
