/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 17:41:20 by rlevine           #+#    #+#             */
/*   Updated: 2017/07/02 17:46:26 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_wordcount(char const *s, char c)
{
	int		prev;
	int		count;

	prev = 0;
	count = 0;
	while (*s)
	{
		if (prev == 1 && c == *s)
			prev = 0;
		if (prev == 0 && c != *s)
		{
			prev = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		sholder;
	char	**new_s;
	int		i;
	int		j;
	int		begin;

	i = 0;
	j = -1;
	if (s == 0 || c == 0)
		return (NULL);
	sholder = ft_wordcount(s, c);
	if (!(new_s = malloc((sizeof(char*) * (sholder + 1)))))
		return (NULL);
	while (++j < sholder)
	{
		while (s[i] && s[i] == c)
			i++;
		begin = i;
		while (s[i] && s[i] != c)
			i++;
		new_s[j] = malloc(sizeof(char*) * ((i - begin) + 1));
		new_s[j] = ft_strsub(s, begin, i - begin);
	}
	new_s[j] = NULL;
	return (new_s);
}
