/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:06:10 by sjones            #+#    #+#             */
/*   Updated: 2017/12/11 15:17:28 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_world	*init_world(char *file)
{
	t_world	*w;

	if (!(w = ft_memalloc(sizeof(*w))))
		exit(-1);
	load_map(w, file);
	w->pos_x = w->map_w / 2;
	w->pos_y = w->map_h / 2;
	w->dir_x = -1;
	w->pln_y = 0.66;
	return (w);
}

static t_input	*init_input(void)
{
	t_input	*i;

	if (!(i = ft_memalloc(sizeof(*i))))
		exit(-1);
	return (i);
}

static t_mlx	*init_mlx(void)
{
	t_mlx	*m;

	if (!(m = ft_memalloc(sizeof(*m))))
		exit(-1);
	m->t = "Wolf_3D";
	m->h = WINDOW_HEIGHT;
	m->w = WINDOW_WIDTH;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->w, m->h, m->t);
	m->img = mlx_new_image(m->mlx, m->w, m->h);
	m->data = (int*)mlx_get_data_addr(m->img, &m->bpp, &m->size, &m->end);
	m->size /= 4;
	return (m);
}

t_super			*init_super(char *file)
{
	t_super *s;

	if (!(s = ft_memalloc(sizeof(*s))))
		exit(-1);
	W = init_world(file);
	I = init_input();
	M = init_mlx();
	handle_music(s);
	return (s);
}

t_thread		*init_thread(t_super *s, int id)
{
	t_thread	*t;

	if (!(t = ft_memalloc(sizeof(*t))))
		exit(-1);
	t->id = id;
	t->map = W->map;
	t->map_w = W->map_w;
	t->map_h = W->map_h;
	t->map_x = W->map_x;
	t->map_y = W->map_y;
	t->pos_x = W->pos_x;
	t->pos_y = W->pos_y;
	t->dir_x = W->dir_x;
	t->dir_y = W->dir_y;
	t->pln_x = W->pln_x;
	t->pln_y = W->pln_y;
	t->data = M->data;
	t->img_h = M->h;
	t->img_w = M->w;
	return (t);
}
