/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_outs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:18:08 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/11 17:46:52 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putint(int num)
{
	int		i;
	long	nb;

	nb = num;
	i = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		i += 1;
	}
	if (nb > 9)
		i += ft_putint(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
	return (i);
}

int	ft_unsign(unsigned int nb)
{
	int	count;

	count = 1;
	if (nb > 9)
		count += ft_putint(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
	return (count);
}

int	ft_puthexlow(const char *str, int i, unsigned int num)
{
	int	count;

	count = 1;
	if (i != 0 && num != 0 && (str[i - 1] == '#'))
		count += ft_putstr("0x");
	if (num > 15)
		count += ft_puthexlow(str, 0, num / 16);
	write(1, &"0123456789abcdef"[num % 16], 1);
	return (count);
}

int	ft_puthexupper(const char *str, int i, unsigned int num)
{
	int	count;

	count = 1;
	if (i != 0 && num != 0 && (str[i - 1] == '#'))
		count += ft_putstr("0X");
	if (num > 15)
		count += ft_puthexupper(str, 0, num / 16);
	write(1, &"0123456789ABCDEF"[num % 16], 1);
	return (count);
}
