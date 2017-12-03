/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:26:36 by sjones            #+#    #+#             */
/*   Updated: 2017/01/20 13:18:51 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_nbrlen(int n)
{
	unsigned int	c;
	unsigned int	nbr;

	c = ((n < 0) ? (1) : (0));
	nbr = ((n < 0) ? ((unsigned int)-n) : ((unsigned int)n));
	while (nbr > 0)
	{
		nbr /= 10;
		c++;
	}
	return (c);
}

static char				*ft_isnbr(int n, char *s, unsigned int p)
{
	unsigned int	nbr;

	p--;
	if (n < 0)
		s[0] = '-';
	nbr = ((n < 0) ? ((unsigned int)-n) : ((unsigned int)n));
	if (nbr >= 10)
	{
		ft_isnbr((nbr / 10), s, p);
		s[p] = ((nbr % 10) + '0');
	}
	else
		s[p] = (nbr + '0');
	return (s);
}

char					*ft_itoa(int n)
{
	int		l;
	char	*ret;

	l = ft_nbrlen(n);
	if (!(ret = (n == 0 ? (ft_strnew(1)) : (ft_strnew(l)))))
		return (NULL);
	return (n == 0 ? (ft_strdup("0")) : (ft_isnbr(n, ret, l)));
}
