/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:11:20 by sjones            #+#    #+#             */
/*   Updated: 2017/12/20 15:52:21 by sjones           ###   ########.fr       */
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
# include <time.h>
# include <pthread.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>

# define W s->world
# define I s->input
# define M s->mlx
# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1000
# define CEILING_COLOR 0xFFFF00
# define FLOOR_COLOR 0x006400
# define S_COLOR 0xFF8C00
# define W_COLOR 0x884600
# define N_COLOR 0xFF8CFF
# define E_COLOR 0x884688
# define MOVE_COEFF 5.0
# define ROTATE_COEFF 3.0
# define THREADS 1
# define FPS 25
# define SKIP_TICKS (1000 / FPS)
# define RED(c) c >> 16
# define GREEN(c) c << 8 >> 16
# define BLUE(c) c << 16 >> 16
# define HALF_COLOR(r, g, b) (r / 2 << 16 | g / 2 << 8 | b / 2)

enum
{
	left,
	right,
	fore,
	back
}					directions;

typedef struct		s_thread
{
	int				id;
	int				x;
	int				y;
	int				hit;
	int				side;
	int				**map;
	int				map_w;
	int				map_h;
	int				map_x;
	int				map_y;
	int				img_w;
	int				img_h;
	int				stp_x;
	int				stp_y;
	int				lin_h;
	int				drw_s;
	int				drw_e;
	double			cam;
	double			pwdis;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			pln_x;
	double			pln_y;
	double			rps_x;
	double			rps_y;
	double			rdr_x;
	double			rdr_y;
	double			sds_x;
	double			sds_y;
	double			dds_x;
	double			dds_y;
	int				*data;
}					t_thread;

typedef struct		s_world
{
	time_t			ctime;
	time_t			otime;
	int				ftime;
	int				**map;
	int				map_w;
	int				map_h;
	int				map_x;
	int				map_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			pln_x;
	double			pln_y;
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
	bool			shift;
	bool			draw;
	bool			music;
	bool			m_choice;
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
	pid_t			music;
}					t_super;

t_super				*init_super(char *file);
t_thread			*init_thread(t_super *s, int id);
void				load_map(t_world *w, char *file);
int					handle_error(char *file);
int					recast(t_super *s);
void				move(int dir, t_super *s);
void				turn(int dir, t_super *s);
int					key_press(int key, t_super *s);
int					key_release(int key, t_super *s);
int					mouse_press(int key, int x, int y, t_super *s);
int					mouse_release(int key, int x, int y, t_super *s);
int					motion_hook(int x, int y, t_super *s);
int					expose_hook(t_super *s);
int					exit_hook(t_super *s);
int					loop_hook(t_super *s);
int					handle_music(t_super *s);

/*
**	Testing funtions
*/

void				print_map(t_super *s);

#endif
