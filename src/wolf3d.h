/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:11:20 by sjones            #+#    #+#             */
/*   Updated: 2017/12/02 20:20:28 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "mlx_keys_macros.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# include <stdio.h>  // FOR DEBUG ONLY TAKE OUT WHEN DONE

# define W s->world
# define I s->input
# define M s->mlx
# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1000

typedef struct		s_world
{
	int				hit;
	int				side;
	int				time;
	int				otime;
	int				**map;
	int				map_w;
	int				map_h;
	int				map_x;
	int				map_y;
	int				stp_x;
	int				stp_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			odr_x;
	double			pln_x;
	double			pln_y;
	double			opn_x;
	double			rps_x;
	double			rps_y;
	double			rdr_x;
	double			rdr_y;
	double			sds_x;
	double			sds_y;
	double			dds_x;
	double			dds_y;
	double			pwdis;
	double			cam_x;
	double			spd_m;
	double			spd_r;
}					t_world;

typedef struct		s_input
{
	int				m_x;
	int				m_y;
	bool			m_l;
	bool			m_r;
	bool			fore;
	bool			back;
	bool			left;
	bool			right;
	bool			l_turn;
	bool			r_turn;
}					t_input;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*t;
	int				*data;
	int				bpp;
	int				size;
	int				end;
	int				h;
	int				w;
}					t_mlx;

typedef struct		s_super
{
	t_world			*world;
	t_input			*input;
	t_mlx			*mlx;
}					t_super;

t_super				*init_super(char *file);
void				load_map(t_world *w, char *file);
int					handle_error(char *file);

/*
**	Testing funtions
*/

void				print_map(t_super *s);

#endif
