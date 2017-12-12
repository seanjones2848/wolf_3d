/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:18:48 by sjones            #+#    #+#             */
/*   Updated: 2017/12/11 17:17:25 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (key == KEY_SHIFT_LEFT || key == KEY_SHIFT_RIGHT)
		I->shift = true;
	if (key == KEY_ESCAPE)
	{
		if (I->music)
			system("killall afplay");
		exit(0);
	}
	if (key == KEY_M)
		handle_music(s);
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
	if (key == KEY_SHIFT_LEFT || key == KEY_SHIFT_RIGHT)
		I->shift = false;
	return (1);
}

int	mouse_press(int key, int x, int y, t_super *s)
{
	if (key == MOUSE_LEFT)
		I->m_l = true;
	if (key == MOUSE_RIGHT)
		I->m_r = true;
	return (x + y);
}

int	mouse_release(int key, int x, int y, t_super *s)
{
	if (key == MOUSE_LEFT)
		I->m_l = false;
	if (key == MOUSE_RIGHT)
		I->m_r = false;
	return (x + y);
}

int	motion_hook(int x, int y, t_super *s)
{
	I->m_x = x - M->w / 2;
	I->m_y = y - M->h / 2;
	return (1);
}
