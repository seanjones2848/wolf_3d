/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:21:38 by sjones            #+#    #+#             */
/*   Updated: 2017/01/11 13:31:29 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		l;

	l = ((ft_strlen(s1) > ft_strlen(s2)) ? ft_strlen(s2) : ft_strlen(s1));
	return (ft_memcmp(s1, s2, (l + 1)));
}
