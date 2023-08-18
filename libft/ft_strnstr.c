/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:16:39 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/12 17:11:27 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0' || little == NULL)
		return ((char *)big);
	if (len > ft_strlen((char *)big))
		len = ft_strlen((char *)big);
	while (i < len && (big[i] != '\0'))
	{
		j = 0;
		while ((big)[i] != (little)[j])
			i++;
		while ((big)[i + j] == (little)[j] && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
