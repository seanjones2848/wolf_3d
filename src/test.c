/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:15:58 by sjones            #+#    #+#             */
/*   Updated: 2017/12/02 20:23:50 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_map(t_super *s)
{
	int i;
	int j;

	i = -1;
	while (++i < W->map_h)
	{
		j = -1;
		while (++j < W->map_w)
		{
			printf("%d", W->map[i][j]);
			if (j < W->map_w - 1)
				printf(", ");
			else
				printf("\n");
		}
	}
	printf("map width:%d map height:%d\n", W->map_w, W->map_h);
}
