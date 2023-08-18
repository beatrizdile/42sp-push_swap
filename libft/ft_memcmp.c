/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:04:32 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/05/13 15:48:04 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			c;
	unsigned char	*s1_chr;
	unsigned char	*s2_chr;

	if (n <= 0)
		return (0);
	s1_chr = (unsigned char *)s1;
	s2_chr = (unsigned char *)s2;
	c = 0;
	while (c < n)
	{
		if (s1_chr[c] != s2_chr[c])
			return (s1_chr[c] - s2_chr[c]);
		else
			c++;
	}
	return (0);
}
