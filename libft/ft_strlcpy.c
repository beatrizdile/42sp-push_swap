/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:36:19 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/11 17:43:25 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strlcpy() copies up to size - 1 characters from the string src to dest, 
// NUL-terminating the result if size is not 0. the strlcpy() function 
// returns the length of the string it tried to create.

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	if (!dest || !src)
		return (0);
	i = 0;
	x = ft_strlen((char *) src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (x);
}
