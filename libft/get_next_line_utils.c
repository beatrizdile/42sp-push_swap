/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:58:36 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/12 19:19:47 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	slash_not_found(char	*str)
{
	int	i;

	i = 1;
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (*str == '\n')
			i = 0;
		str++;
	}
	return (i);
}

char	*put_rest_in_total(char	*buf)
{
	char	*temp;
	size_t	i;
	size_t	j;

	if (buf == NULL || *buf == '\0')
	{
		free(buf);
		return (NULL);
	}
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	j = ft_strlen(buf) - i;
	temp = (char *)malloc(sizeof(char) * j + 1);
	if (!temp)
		return (NULL);
	j = 0;
	while (buf[i++] != '\0')
		temp[j++] = buf[i];
	temp[j] = '\0';
	free(buf);
	return (temp);
}

char	*str_to_first_n(char	*total)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	if (!total)
		return (NULL);
	while (total[i] != '\n' && total[i] != '\0')
		i++;
	if (total[i] == '\0')
		temp = (char *)malloc(sizeof(char) * (i + 1));
	else
		temp = (char *)malloc(sizeof(char) * (i++ + 2));
	if (!temp)
		return (NULL);
	j = 0;
	while (j < i)
	{
		temp[j] = total[j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*add_to_dest(char *total, char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (total == NULL)
	{
		total = malloc(sizeof(char));
		total[0] = '\0';
	}
	new = (char *)malloc((ft_strlen(total) + ft_strlen(buffer)) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (total[i] != '\0')
	{
		new[i] = total[i];
		i++;
	}
	j = 0;
	while (buffer[j] != '\0')
		new[i++] = buffer[j++];
	new[i] = '\0';
	free(total);
	return (new);
}
