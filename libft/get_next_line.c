/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:33:52 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/08/12 19:31:58 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	int				i;
	char			*buffer;
	static char		*total[4096];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0))
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (slash_not_found(total[fd]))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
			break ;
		buffer[i] = '\0';
		total[fd] = add_to_dest(total[fd], buffer);
	}
	free(buffer);
	buffer = str_to_first_n(total[fd]);
	total[fd] = put_rest_in_total(total[fd]);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		free(total[fd]);
		buffer = NULL;
	}
	return (buffer);
}
