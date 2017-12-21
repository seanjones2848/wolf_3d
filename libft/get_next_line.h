/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:09:48 by sjones            #+#    #+#             */
/*   Updated: 2017/12/20 16:41:26 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 1
# define MAX_FD 2048

int						get_next_line(const int fd, char **line);

typedef struct			s_stor
{
	int					rl;
	char				buff[BUFF_SIZE + 1];
	char				*lo;
	char				*t;
}						t_stor;

#endif
