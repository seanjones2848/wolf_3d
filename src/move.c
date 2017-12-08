#include "wolf3d.h"

void	turn(int dir, t_super *s)
{
	double	odr_x;
	double	opn_x;

	if (dir == left)
	{
		odr_x = W->dir_x;
		W->dir_x = W->dir_x * cos(W->spd_r) - W->dir_y * sin(W->spd_r);
		W->dir_y = odr_x * sin(W->spd_r) - W->dir_y * cos(W->spd_r);
		opn_x = W->pln_x;
		W->pln_x = W->pln_x * cos(W->spd_r) - W->pln_y * sin(W->spd_r);
		W->pln_y = opn_x * sin(W->spd_r) - W->pln_y * cos(W->spd_r);
	}
	if (dir == right)
	{
		odr_x = W->dir_x;
		W->dir_x = W->dir_x * cos(-W->spd_r) - W->dir_y * sin(-W->spd_r);
		W->dir_y = odr_x * sin(-W->spd_r) - W->dir_y * cos(-W->spd_r);
		opn_x = W->pln_x;
		W->pln_x = W->pln_x * cos(-W->spd_r) - W->pln_y * sin(-W->spd_r);
		W->pln_y = opn_x * sin(-W->spd_r) - W->pln_y * cos(-W->spd_r);
	}
	I->draw = true;
}

void	move(int dir, t_super *s)
{
	if (dir == fore)
	{
		if (!W->map[(int)(W->pos_x + W->dir_x * W->spd_m)][(int)(W->pos_y)])
			W->pos_x += W->dir_x * W->spd_m;
		if (!W->map[(int)(W->pos_x)][(int)(W->pos_y + W->dir_y * W->spd_m)])
			W->pos_y += W->dir_y * W->spd_m;
	}
	if (dir == back)
	{
		if (!W->map[(int)(W->pos_x - W->dir_x * W->spd_m)][(int)(W->pos_y)])
			W->pos_x -= W->dir_x * W->spd_m;
		if (!W->map[(int)(W->pos_x)][(int)(W->pos_y - W->dir_y * W->spd_m)])
			W->pos_y -= W->dir_y * W->spd_m;
	}
	I->draw = true;
}
