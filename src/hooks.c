#include "wolf3d.h"

int	key_press(int key, t_super *s)
{
	if (key == KEY_A || key == KEY_LEFT)
		I->left = true;
	if (key == KEY_D || key == KEY_RIGHT)
		I->right = true;
	if (key == KEY_S || key == KEY_DOWN)
		I->back = true;
	if (key == KEY_W || key == KEY_UP)
		I->fore = true;
	if (key == KEY_ESCAPE)
		exit(0);
	return (1);
}

int	key_release(int key, t_super *s)
{
	if (key == KEY_A || key == KEY_LEFT)
		I->left = false;
	if (key == KEY_D || key == KEY_RIGHT)
		I->right = false;
	if (key == KEY_S || key == KEY_DOWN)
		I->back = false;
	if (key == KEY_W || key == KEY_UP)
		I->fore = false;
	return (1);
}

int mouse_press(int key, int x, int y, t_super *s)
{
	if (key == MOUSE_LEFT)
		I->m_l = true;
	if (key == MOUSE_RIGHT)
		I->m_r = true;
	return (x + y);
}

int mouse_release(int key, int x, int y, t_super *s)
{
	if (key == MOUSE_LEFT)
		I->m_l = false;
	if (key == MOUSE_RIGHT)
		I->m_r = false;
	return (x + y);
}

int motion_hook(int x, int y, t_super *s)
{
	I->m_x = x - M->w / 2;
	I->m_y = y - M->h / 2;
	return (1);
}
