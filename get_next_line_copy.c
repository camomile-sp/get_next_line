/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:42:28 by marvin            #+#    #+#             */
/*   Updated: 2025/02/13 17:42:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;
	char	*buf;
	char	*pos_n;
	char	*temp_stash;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		if (!stash)
			stash = ft_strdup(buf);
		else
			{
				temp_stash = ft_strjoin(stash, buf);
				free(stash);
				stash = temp_stash;
			}
		pos_n = ft_strchr(stash, '\n');
		if (pos_n)
		{
			//fill_line
			line = ft_substr(stash, 0, ((pos_n - stash) + 1));
			temp_stash = ft_substr(stash, ((pos_n - stash) + 1), (ft_strlen(stash)-((pos_n - stash) + 1)));
			free(stash);
			stash = temp_stash;
		}
	}
	free(buf);
	return (line);
}