/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:34:07 by sjones            #+#    #+#             */
/*   Updated: 2017/01/19 18:30:09 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	temp;

	temp = n;
	if (temp < 0)
	{
		ft_putchar_fd('-', fd);
		temp = -temp;
	}
	if (temp > 9)
	{
		ft_putnbr_fd(temp / 10, fd);
		ft_putnbr_fd(temp % 10, fd);
	}
	else
		ft_putchar_fd(temp + '0', fd);
}
