/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:34:07 by sjones            #+#    #+#             */
/*   Updated: 2017/02/14 21:10:56 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	temp;

	temp = n;
	if (temp < 0)
	{
		ft_putchar('-');
		temp = -temp;
	}
	if (temp > 9)
	{
		ft_putnbr(temp / 10);
		ft_putnbr(temp % 10);
	}
	else
		ft_putchar(temp + 48);
}
