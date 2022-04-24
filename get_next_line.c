/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:04:21 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/24 15:41:06 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*ft_next(char *buffer)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		tmp[j++] = buffer[i++];
	free(buffer);
	return (tmp);
}

char	*ft_line(char *buffer)
{
	char	*tmp;
	int		i;

	i = 0;
	if (buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\0')
		i++;
	tmp = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] == '\n')
	{
		tmp[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		tmp[i++] = '\n';
	return (tmp);
}

char	*ft_file(int fd, char *result)
{
	char	*buffer;
	int		ft_read;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	ft_read = 1;
	while (ft_read > 0)
	{
		ft_read = read(fd, buffer, BUFFER_SIZE);
		if (ft_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ft_read] = 0;
		result = ft_free(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
