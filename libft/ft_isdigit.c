/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:55:20 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/05/01 10:13:07 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RETURN VALUE: The values returned are nonzero if the character c falls into 
// the tested class, and a zero value if not.

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
