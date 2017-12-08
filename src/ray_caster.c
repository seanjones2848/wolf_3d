#include "wolf3d.h"

static void	dda(t_thread *t)
{
	while (t->hit == 0)
	{
		if (t->sds_x < t->sds_y)
		{
			t->sds_x += t->dds_x;
			t->map_x += t->stp_x;
			t->side = 0;
		}
		else
		{
			t->sds_y += t->dds_y;
			t->map_y += t->stp_y;
			t->side = 1;
		}
		t->hit = t->map[t->map_x][t->map_y] > 0 ? (1) : (0);
	}
	t->pwdis = (t->side == 0) ? ((t->map_x - t->rps_x + (1 - t->stp_x) / 2) /
		t->rdr_x) : ((t->map_y - t->rps_y + (1 - t->stp_y) / 2) / t->rdr_y);
}

static void	draw_line(t_thread *t)
{
	t->lin_h = (int)(M->h / t->pwdis);
	t->drw_s = (-t->lin_h / 2 + M->h / 2) < 0 ? (0) : (-t->lin_h / 2 + M->h / 2);
	t->drw_e = (t->lin_h / 2 + M->h / 2) >= M->h ? (M->h - 1) :
		(t->lin_h / 2 + M->h /2);
	t->y = -1;
	while (++t->y < M->h)
	{
		if (t->y < t->drw_s)
			M->data[t->x + M->w * t->y] = CEILING_COLOR;
		else if (t->y < t->drw_e)
			M->data[t->x + M->w * t->y] = t->side == 0 ? (WALL_COLOR) : (WALL_COLOR / 2);
		else
			M->data[t->x + M->w * t->y] = FLOOR_COLOR;
	}
}

static void	ray_casting(t_thread *t)
{
	t->x = -1;
	while (++t->x < M->w)
	{
		t->cam = 2 * t->x / (double)M->w - 1;
		t->rps_x = t->pos_x;
		t->rps_y = t->pos_y;
		t->rdr_x = t->dir_x + t->pln_x * t->cam;
		t->rdr_y = t->dir_y + t->pln_y * t->cam;
		t->map_x = (int)t->rps_x;
		t->map_y = (int)t->rps_y;
		t->sds_x = t->rdr_x < 0 ? ((t->rps_x - t->map_x) * t->dds_x) :
			((t->map_x + 1.0 - t->rps_x) * t->dds_x);
		t->sds_y = t->rdr_y < 0 ? ((t->rps_y - t->map_y) * t->dds_y) :
			((t->map_y + 1.0 - t->rps_y) * t->dds_y);
		t->dds_x = sqrt(1 + (t->rdr_y * t->rdr_y) / (t->rdr_x * t->rdr_x));
		t->dds_y = sqrt(1 + (t->rdr_x * t->rdr_x) / (t->rdr_y * t->rdr_y));
		t->pwdis = 0;
		t->stp_x = t->rdr_x < 0 ? (-1) : (1);
		t->stp_y = t->rdr_y < 0 ? (-1) : (1);
		t->hit = 0;
		t->side = 0;
		dda(s);
		draw_line(s);
	}
}

static void	*ray_runner(void *v)
{
	t_thread	*t;

	t = (t_thread*)v;
	ray_casting(t);
	free(t);
	pthread_exit(0);
}

int			recast(t_super *s)
{
	pthread_t	tids[THREADS];
	t_thread	*t;
	int			i;

	i = -1;
	while (++i < THREADS)
	{
		t = init_thread(s, i + 1);
		pthread_create(&tids[i], NULL, ray_runner, t);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(tids[i], NULL);
	W->otime = W->ctime;
	W->ctime = time(NULL);
	W->ftime = difftime(W->otime, W->ctime);
	printf("fps: {%f}\n", 1.0 / W->ftime);
	W->spd_m = W->ftime * MOVE_COEFF;
	W->spd_r = W->ftime * ROTATE_COEFF;
	mlx_put_image_to_window(M->mlx, M->win, M->img, 0, 0);
	return (1);
}
