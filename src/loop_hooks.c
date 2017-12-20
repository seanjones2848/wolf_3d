/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:19:13 by sjones            #+#    #+#             */
/*   Updated: 2017/12/20 15:53:03 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	expose_hook(t_super *s)
{
	I->draw = true;
	return (1);
}

int	exit_hook(t_super *s)
{
	if (I->music)
		system("killall afplay");
	exit(0);
	return (1);
}

int	loop_hook(t_super *s)
{
	if (I->draw && recast(s))
		I->draw = false;
	if (I->right)
		turn(right, s);
	if (I->left)
		turn(left, s);
	if (I->fore)
		move(fore, s);
	if (I->back)
		move(back, s);
	return (1);
}
