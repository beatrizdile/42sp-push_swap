/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:00:35 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/05/11 12:46:34 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The bzero() function sets the first n bytes of the area starting at s to 
// zero (bytes containing aq\0aq).

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{	
	ft_memset(s, 0, n);
}
