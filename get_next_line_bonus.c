/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:47:52 by kinamura          #+#    #+#             */
/*   Updated: 2024/05/04 19:10:59 by kinamura         ###   ########.fr       */
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
	char    	*buf;
	ssize_t		size;

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
	static char	*str[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_file(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_next_str(str[fd]);
	return (line);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <fcntl.h>
// int main (void)
// {
//     char *line;
//     int fd;
//     int i = 1;
//     fd = open("test/test.txt", O_RDONLY);
//     while (42)
//     {
//         printf("%d:",i);
//         line = get_next_line(fd);
//         if (!line)
//             break ;
//         printf("%s", line);
//         i++;
//     }
//     close(fd);
//     return (0);
// }
