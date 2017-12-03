/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:26:02 by sjones            #+#    #+#             */
/*   Updated: 2017/12/02 20:15:34 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_end(char *file)
{
	int i;

	if (ft_strlen(file) <= 4)
		return (1);
	i = ft_strlen(file) - 4;
	if (ft_strcmp(file + i, ".wlf"))
		return (1);
	return (0);
}

static int	row_count(char **row)
{
	int r;

	r = 0;
	while (row[r])
		r++;
	return r;
}

static int	check_map(char *file)
{
	int		fd;
	char	*row;
	int		r_len;
	int		r_len2;

	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &row) > 0)
		r_len = row_count(ft_strsplit(row, ' '));
	else
		return (1);
	while (get_next_line(fd, &row) > 0)
	{
		r_len2 = row_count(ft_strsplit(row, ' '));
		if (r_len != r_len2)
			return (1);
	}
	close(fd);
	return (0);
}

int			handle_error(char *file)
{
	if (check_end(file) || check_map(file))
		return (1);
	return (0);
}
