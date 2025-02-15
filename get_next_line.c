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
	char	*temp_stash;
	char	*buf;
	char	*pos_n;
	int	len;

	len = 0;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf || read(fd, buf, BUFFER_SIZE) <= 0)
	{
		free(buf);
		return (NULL);
	}
	while (1)
	{
		stash = ft_strjoin(stash, buf);
		if (ft_strchr(stash, '\n') != NULL)
		{
			pos_n = ft_strchr(stash, '\n');
			if (pos_n)
				len = (pos_n - stash) + 1;
			line = ft_substr(stash, 0, len);
			temp_stash = ft_substr(stash, len, ft_strlen(stash) - len);
			free(stash);
			if (temp_stash)
			{
				stash = ft_strdup(temp_stash);
				free(temp_stash);
			}
			free(buf);
			return (line);
		}
	}
}
