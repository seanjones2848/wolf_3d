/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:26:45 by sjones            #+#    #+#             */
/*   Updated: 2017/01/25 20:52:54 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp;

	temp = malloc(sizeof(char) * len);
	if (temp)
	{
		ft_memcpy(temp, src, len);
		ft_memcpy(dst, temp, len);
	}
	return (dst);
}
