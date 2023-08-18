/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:37:14 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/05/04 08:29:12 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// To use the elements inside the returned array s: (unsigned char *)s[i]

#include "libft.h"

void	*ft_memset(void *s, int c, size_t x)
{
	size_t	i;

	i = 0;
	while (i < x)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
