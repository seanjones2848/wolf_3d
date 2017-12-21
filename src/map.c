/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:23:38 by sjones            #+#    #+#             */
/*   Updated: 2017/12/20 17:57:06 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	get_map_details(t_world *w, char *file)
{
	char	*line;
	char	**row;
	int		fd;
	int		i;
	int		f;

	f = 0;
	i = -1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (f == 0)
		{
			row = ft_strsplit(line, ' ');
			while (row[++i])
			{
				w->map_w++;
			}
			f = 1;
			free_2char(row);
		}
		w->map_h++;
		free(line);
	}
	close(fd);
}

static void	load_row(t_world *w, int i, char **row)
{
	int	j;

	j = -1;
	if (!(w->map[i] = ft_memalloc(sizeof(int) * w->map_w)))
		exit(-1);
	while (row[++j])
	{
		w->map[i][j] = ft_atoi(row[j]);
		free(row[j]);
	}
	free(row);
}

void		load_map(t_world *w, char *file)
{
	char	*line;
	int		fd;
	int		i;

	get_map_details(w, file);
	if (!(w->map = ft_memalloc(sizeof(int*) * w->map_h)))
		exit(1);
	fd = open(file, O_RDONLY);
	i = -1;
	while (get_next_line(fd, &line))
	{
		load_row(w, ++i, ft_strsplit(line, ' '));
		free(line);
	}
	close(fd);
}
