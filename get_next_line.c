/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:47:45 by kinamura          #+#    #+#             */
/*   Updated: 2024/05/04 19:11:12 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	size_t	index;
	size_t	n_flag;
	char	*buf;

	index = 0;
	if (!str[index])
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	n_flag = 0;
	if (str[index] == '\n')
		n_flag = 1;
	buf = (char *)malloc(sizeof(char) * (index + n_flag + 1));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, str, index + n_flag + 1);
	return (buf);
}

char	*ft_next_str(char *str)
{
	size_t	index;
	char	*buf;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (ft_strlen(str) - index + 1));
	if (!buf)
	{
		free(str);
		return (NULL);
	}
	index++;
	ft_strlcpy(buf, &str[index], (ft_strlen(str) - index + 1));
	free(str);
	return (buf);
}

char	*ft_read_file(int fd, char *str)
{
	char	*buf;
	int		size;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = 1;
	while (!ft_strchr(str, '\n') && size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[size] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > OPEN_MAX)
		return (NULL);
	str = ft_read_file(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_next_str(str);
	return (line);
}
