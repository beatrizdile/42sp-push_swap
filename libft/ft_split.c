/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:52:29 by ada-cruz          #+#    #+#             */
/*   Updated: 2023/08/08 16:24:57 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenuc(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static int	nmbr_of_word(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**splitstr;

	i = 0;
	splitstr = (char **)ft_calloc((nmbr_of_word(s, c) + 1), sizeof(char *));
	if (!splitstr)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			splitstr[i] = (char *)ft_calloc((lenuc(s, c) + 1), sizeof(char));
			if (!splitstr[i])
				return (NULL);
			j = 0;
			while (*s != c && *s)
				splitstr[i][j++] = *s++;
			i++;
		}
	}
	return (splitstr);
}
