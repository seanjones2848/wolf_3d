/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:14:57 by sjones            #+#    #+#             */
/*   Updated: 2017/12/20 18:15:00 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	input_line(char **input, char **line, int fd, int ret)
{
	char	*temp;
	int		len;

	len = 0;
	while (input[fd][len] && input[fd][len] != '\n')
		len++;
	if (input[fd][len] == '\n')
	{
		*line = ft_strsub(input[fd], 0, len);
		temp = ft_strdup(input[fd] + len + 1);
		free(input[fd]);
		input[fd] = temp;
	}
	else if (!input[fd][len])
	{
		if (ret == BUFF_SIZE)
			return (0);
		*line = ft_strdup(input[fd]);
		free(input[fd]);
		input[fd] = NULL;
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*input[5000];
	char			*temp;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!input[fd])
			input[fd] = ft_strnew(0);
		buf[ret] = '\0';
		temp = ft_strjoin(input[fd], buf);
		free(input[fd]);
		input[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (!ret && (!input[fd] || !input[fd][0]))
		return (0);
	return (input_line(input, line, fd, ret));
}
