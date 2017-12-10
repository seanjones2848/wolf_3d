/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:20:46 by sjones            #+#    #+#             */
/*   Updated: 2017/12/10 14:23:12 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_super	*s;

	if (ac != 2 || handle_error(av[1]))
	{
		write(1, "Please put in a valid .wlf map please\n", 38);
		exit(-1);
	}
	s = init_super(av[1]);
	mlx_hook(M->win, 2, 0, key_press, s);
	mlx_hook(M->win, 3, 0, key_release, s);
//	mlx_hook(M->win, 4, 0, mouse_press, s);
//	mlx_hook(M->win, 5, 0, mouse_release, s);
//	mlx_hook(M->win, 6, 0, motion_hook, s);
	mlx_hook(M->win, 12, 0, expose_hook, s);
	mlx_loop_hook(M->mlx, loop_hook, s);
	mlx_loop(M->mlx);
	return (0);
}
