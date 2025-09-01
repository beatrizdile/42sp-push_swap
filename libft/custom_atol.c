/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:33:13 by fnicolau          #+#    #+#             */
/*   Updated: 2025/09/01 13:47:16 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	validate_limits(const char *s, int signal)
{
	size_t	len;

	len = ft_strlen(s);
	while (*s == '0')
	{
		s++;
		len--;
	}
	if (signal == -1)
	{
		if (len > 10 || (len == 10 && ft_strcmp(s, "2147483648") > 0))
			return (false);
	}
	else
	{
		if (len > 10 || (len == 10 && ft_strcmp(s, "2147483647") > 0))
			return (false);
	}
	return (true);
}

long	custom_atol(const char *nptr)
{
	size_t	i;
	int		signal;
	long	result;

	if (!nptr)
		return (LONG_MAX);
	i = 0;
	signal = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			signal = -1;
	}
	if (!validate_limits(nptr + i, signal))
		return (LONG_MAX);
	while (ft_isdigit(nptr[i]))
	{
		result = (result * 10) + nptr[i] - '0';
		i++;
	}
	return (result * signal);
}
