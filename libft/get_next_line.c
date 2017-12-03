/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:24:41 by sjones            #+#    #+#             */
/*   Updated: 2017/02/20 17:17:54 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_stor	**getinit(t_stor **get, int fd)
{
	if (!get)
		get = (t_stor**)ft_memalloc((sizeof(t_stor*) * MAX_FD));
	get[fd] = (t_stor*)ft_memalloc(sizeof(t_stor));
	get[fd]->rl = 0;
	get[fd]->lo = 0;
	get[fd]->t = 0;
	return (get);
}

int		putline(t_stor *get, char *s, char **line)
{
	if (!get || !s || !line)
		return (-1);
	get->t = s;
	if (*(get->t) && (ft_strchr(get->t, '\n') != NULL))
	{
		*line = ft_strndup(get->t, (ft_strchr(get->t, '\n') - s));
		get->lo = ft_strdup(ft_strchr(get->t, '\n') + 1);
		if (ft_strcmp(get->t, get->buff) != 0)
			free(get->t);
		return (1);
	}
	if (*(get->t) && (get->rl < BUFF_SIZE))
	{
		*line = ft_strdup(get->t);
		get->lo = NULL;
		if (ft_strcmp(get->t, get->buff) != 0)
			free(get->t);
		return (1);
	}
	return (0);
}

void	buff_join(t_stor *get)
{
	get->t = get->lo;
	get->lo = ft_strjoin(get->t, get->buff);
	if (*get->t)
		free(get->t);
}

void	helper(t_stor *get)
{
	if (!(get->lo))
		get->lo = ft_strdup(get->buff);
	else
		buff_join(get);
}

int		get_next_line(int fd, char **line)
{
	static t_stor	**get;

	if (fd < 0 || !line || fd > MAX_FD)
		return (-1);
	if (!get || !get[fd])
		get = getinit(get, fd);
	if (putline(get[fd], get[fd]->lo, line) == 1)
		return (1);
	while ((get[fd]->rl = read(fd, get[fd]->buff, BUFF_SIZE)) || get[fd]->lo)
	{
		if ((int)get[fd]->rl == -1)
			return (-1);
		get[fd]->buff[get[fd]->rl] = '\0';
		if (ft_strchr(get[fd]->buff, '\n') || get[fd]->rl < BUFF_SIZE)
		{
			if (get[fd]->lo)
			{
				buff_join(get[fd]);
				return (putline(get[fd], get[fd]->lo, line));
			}
			return (putline(get[fd], get[fd]->buff, line));
		}
		helper(get[fd]);
	}
	return (0);
}
