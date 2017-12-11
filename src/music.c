/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:47:43 by sjones            #+#    #+#             */
/*   Updated: 2017/12/11 15:23:52 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	play_music(t_super *s)
{
	I->m_choice ? system("afplay songs/virtual_boy.mp3 &") :
		system("afplay songs/polyhurt.mp3 &");
	I->m_choice = I->m_choice ? (false) : (true);
	I->music = true;
}

static void	stop_music(t_super *s)
{
	system("killall afplay");
	I->music = false;
}

int			handle_music(t_super *s)
{
	I->music ? stop_music(s) : play_music(s);
	return (1);
}
