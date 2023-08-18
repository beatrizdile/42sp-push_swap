/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:37:08 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/08 14:09:01 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The first while will take off the characters at the beginning, by making s1
// to start at the first char that isn't on the 'set'. Then we count len--; to
// every char that is on the 'set', but at the end of the str. Then we use
// substr to make the return value, the size max used in substr is the len of
// s1 minus the chars at the end.

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s_len = ft_strlen((char *)s1) - 1;
	while (s_len && ft_strchr(set, s1[s_len]))
		s_len--;
	return (ft_substr(s1, 0, s_len + 1));
}
