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
	if (dir == fore)
	{
		if (!W->map[(int)(W->pos_x + W->dir_x * 0.25)][(int)(W->pos_y)])
			W->pos_x += W->dir_x * 0.25;
		if (!W->map[(int)(W->pos_x)][(int)(W->pos_y + W->dir_y * 0.25)])
			W->pos_y += W->dir_y * 0.25;
	}
	if (dir == back)
	{
		if (!W->map[(int)(W->pos_x - W->dir_x * 0.25)][(int)(W->pos_y)])
			W->pos_x -= W->dir_x * 0.25;
		if (!W->map[(int)(W->pos_x)][(int)(W->pos_y - W->dir_y * 0.25)])
			W->pos_y -= W->dir_y * 0.25;
	}
	I->draw = true;
}
