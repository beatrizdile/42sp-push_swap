/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:52:26 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/05/12 16:01:40 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen((char *)s);
	if (start > str_len)
		return (ft_strdup(""));
	if (str_len - start >= len)
		dest = (char *)malloc((len + 1) * sizeof(char));
	else
		dest = (char *)malloc((str_len - start + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (s + start), (len + 1));
	return (dest);
}
