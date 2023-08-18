/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:17:16 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/07/12 17:13:07 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;
	int		count;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	count = 0;
	while (i < ft_strlen((char *)s))
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_putptr(unsigned long num, int i)
{
	int	count;

	count = 1;
	if (num == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	if (i == 0)
	{
		ft_putstr("0x");
		count += 2;
	}
	if (num > 15)
		count += ft_putptr(num / 16, ++i);
	write(1, &"0123456789abcdef"[num % 16], 1);
	return (count);
}

int	convertions(const char *str, int i, va_list arg)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (str[i] == 'p')
		count += ft_putptr(va_arg(arg, unsigned long), 0);
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_putint(va_arg(arg, int));
	else if (str[i] == 'u')
		count += ft_unsign(va_arg(arg, unsigned int));
	else if (str[i] == 'x')
		count += ft_puthexlow(str, i, va_arg(arg, unsigned long));
	else if (str[i] == 'X')
		count += ft_puthexupper(str, i, va_arg(arg, unsigned long));
	else if (str[i] == '%')
		count += ft_putchar(str[i]);
	return (count);
}
