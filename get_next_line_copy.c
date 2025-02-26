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
	char	*temp;
	char	*pos_n;
	int	len;

	len = 0;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (read(fd, temp, BUFFER_SIZE) > 0)
	{
		temp[BUFFER_SIZE] = '\0';
		if (!stash)
			stash = ft_strdup(temp);
		else
			{
				temp = ft_strjoin(temp, stash);
				free(stash);
				stash = temp;
			}
		pos_n = ft_strchr(stash, '\n');
		if (pos_n)
		{
			len = (pos_n - stash) + 1;
			line = ft_substr(stash, 0, len);
			temp = ft_substr(stash, len, (ft_strlen(stash)-len));
			free(stash);
			stash = temp;
			return (line);
		}
	}
	free(temp);
	return (NULL);
}