#include "wolf3d.h"

int	expose_hook(t_super *s)
{
	I->draw = true;
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
