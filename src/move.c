/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:18:39 by sjones            #+#    #+#             */
/*   Updated: 2017/12/11 17:19:14 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	turn(int dir, t_super *s)
{
	double	odr_x;
	double	opn_x;

	if (dir == left)
	{
		odr_x = W->dir_x;
		W->dir_x = W->dir_x * cos(0.05) - W->dir_y * sin(0.05);
		W->dir_y = odr_x * sin(0.05) + W->dir_y * cos(0.05);
		opn_x = W->pln_x;
		W->pln_x = W->pln_x * cos(0.05) - W->pln_y * sin(0.05);
		W->pln_y = opn_x * sin(0.05) + W->pln_y * cos(0.05);
	}
	if (dir == right)
	{
		odr_x = W->dir_x;
		W->dir_x = W->dir_x * cos(-0.05) - W->dir_y * sin(-0.05);
		W->dir_y = odr_x * sin(-0.05) + W->dir_y * cos(-0.05);
		opn_x = W->pln_x;
		W->pln_x = W->pln_x * cos(-0.05) - W->pln_y * sin(-0.05);
		W->pln_y = opn_x * sin(-0.05) + W->pln_y * cos(-0.05);
	}
	I->draw = true;
}

void	move(int dir, t_super *s)
{
	double	move;

	move = I->shift ? (0.25) : (0.125);
	if (dir == fore)
	{
		if (!W->map[(int)(W->pos_x + W->dir_x * move)][(int)(W->pos_y)])
			W->pos_x += W->dir_x * move;
		if (!W->map[(int)(W->pos_x)][(int)(W->pos_y + W->dir_y * move)])
			W->pos_y += W->dir_y * move;
	}
	if (dir == back)
	{
		if (!W->map[(int)(W->pos_x - W->dir_x * move)][(int)(W->pos_y)])
			W->pos_x -= W->dir_x * move;
		if (!W->map[(int)(W->pos_x)][(int)(W->pos_y - W->dir_y * move)])
			W->pos_y -= W->dir_y * move;
	}
	I->draw = true;
}
