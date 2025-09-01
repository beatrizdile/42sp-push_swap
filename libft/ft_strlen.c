/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:29:17 by bedos-sa          #+#    #+#             */
/*   Updated: 2025/09/01 13:41:04 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RETURN VALUE: The strlen() function returns the number of bytes in the
// string str.

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
