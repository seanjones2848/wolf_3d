/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:26:02 by sjones            #+#    #+#             */
/*   Updated: 2017/12/21 15:58:29 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_end(char *file)
{
	struct stat	buf;
	int			i;
	int			x;

	x = lstat(file, &buf);
	if (S_ISLNK(buf.st_mode))
		return (1);
	if (ft_strlen(file) <= 4)
		return (1);
	i = ft_strlen(file) - 4;
	if (ft_strcmp(file + i, ".wlf"))
		return (1);
	return (0);
}

static int	row_count(char **row, int f)
{
	int r;
	int i;

	r = 0;
	while (row[r])
	{
		if (!ft_isdigit(row[r][0]) && free_2char(row))
			return (-1);
		i = ft_atoi(row[r]);
		if ((f && i == 1) || (f == 0 && (i == 0 || i == 1)))
			r++;
		else
		{
			free_2char(row);
			return (-1);
		}
	}
	if ((row[0][0] != '1' || row[r - 1][0] != '1'))
		return (-1);
	free_2char(row);
	return (r);
}

static int	check_map(char *file, int h)
{
	int		fd;
	char	*row;
	int		r_len;
	int		r_len2;
	int		height;

	height = 0;
	fd = open(file, O_RDONLY);
	if ((get_next_line(fd, &row) > 0) &&
			(r_len = row_count(ft_strsplit(row, ' '), 1)))
		free(row);
	else
		return (1);
	while (get_next_line(fd, &row) > 0)
	{
		r_len2 = row_count(ft_strsplit(row, ' '), 0);
		if (r_len != r_len2)
			return (1);
		if (++height != h)
			free(row);
	}
	if (height < 2 || r_len < 2 || row_count(ft_strsplit(row, ' '), 1) == -1)
		return (1);
	free(row);
	close(fd);
	return (0);
}

int			handle_error(char *file)
{
	char	*line;
	int		fd;
	int		h;

	h = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		h++;
		free(line);
	}
	close(fd);
	if (check_end(file) || check_map(file, h - 1))
		return (1);
	return (0);
}
