/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:18:01 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/05/12 15:59:33 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = ft_strlen((char *)s);
	ch = (unsigned char)c;
	if (s[i] == '\0' && ch == '\0')
		return ((char *)&s[i]);
	else
	{
		i--;
		while (i >= 0)
		{
			if (s[i] == ch)
				return ((char *)&s[i]);
			i--;
		}
	}
	return (NULL);
}
