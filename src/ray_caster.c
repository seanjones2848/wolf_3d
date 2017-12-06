#include "wolf3d.h"

static void	dda(t_super *s)
{
	while (W->hit == 0)
	{
		if (W->sds_x < W->sds_y)
		{
			W->sds_x += W->dds_x;
			W->map_x += W->stp_x;
			W->side = 0;
		}
		else
		{
			W->sds_y += W->dds_y;
			W->map_y += W->stp_y;
			W->side = 1;
		}
		W->hit = W->map[W->map_x][W->map_y] > 0 ? (1) : (0);
	}
	W->pwdis = (W->side == 0) ? ((W->map_x - W->rps_x + (1 - W->stp_x) / 2) /
		W->rdr_x) : ((W->map_y - W->rps_y + (1 - W->stp_y) / 2) / W->rdr_y);
}

static void	draw_line(t_super *s)
{
	W->lin_h = (int)(M->h / W->pwdis);
	W->drw_s = (-W->lin_h / 2 + M->h / 2) < 0 ? (0) : (-W->lin_h / 2 + M->h / 2);
	W->drw_e = (W->lin_h / 2 + M->h / 2) >= M->h ? (M->h - 1) :
		(W->lin_h / 2 + M->h /2);
	W->y = -1;
	while (++W->y < M->h)
	{
		if (W->y < W->drw_s)
			M->data[W->x + M->w * W->y] = CEILING_COLOR;
		else if (W->y < W->drw_e)
			M->data[W->x + M->w * W->y] = W->side == 0 ? (WALL_COLOR) : (WALL_COLOR / 2);
		else
			M->data[W->x + M->w * W->y] = FLOOR_COLOR;
	}
}

static void	ray_casting(t_super *s)
{
	W->x = -1;
	while (++W->x < M->w)
	{
		W->cam = 2 * W->x / (double)M->w - 1;
		W->rps_x = W->pos_x;
		W->rps_y = W->pos_y;
		W->rdr_x = W->dir_x + W->pln_x * W->cam;
		W->rdr_y = W->dir_y + W->pln_y * W->cam;
		W->map_x = (int)W->rps_x;
		W->map_y = (int)W->rps_y;
		W->sds_x = W->rdr_x < 0 ? ((W->rps_x - W->map_x) * W->dds_x) :
			((W->map_x + 1.0 - W->rps_x) * W->dds_x);
		W->sds_y = W->rdr_y < 0 ? ((W->rps_y - W->map_y) * W->dds_y) :
			((W->map_y + 1.0 - W->rps_y) * W->dds_y);
		W->dds_x = sqrt(1 + (W->rdr_y * W->rdr_y) / (W->rdr_x * W->rdr_x));
		W->dds_y = sqrt(1 + (W->rdr_x * W->rdr_x) / (W->rdr_y * W->rdr_y));
		W->pwdis = 0;
		W->stp_x = W->rdr_x < 0 ? (-1) : (1);
		W->stp_y = W->rdr_y < 0 ? (-1) : (1);
		W->hit = 0;
		W->side = 0;
		dda(s);
		draw_line(s);
	}
}

int			recast(t_super *s)
{
	ray_casting(s);
	W->otime = W->ctime;
	W->ctime = time(NULL);
	W->ftime = difftime(W->otime, W->ctime);
	printf("fps: {%f}\n", 1.0 / W->ftime);
	W->spd_m = W->ftime * MOVE_COEFF;
	W->spd_r = W->ftime * ROTATE_COEFF;
	mlx_put_image_to_window(M->mlx, M->win, M->img, 0, 0);
	return (1);
}
