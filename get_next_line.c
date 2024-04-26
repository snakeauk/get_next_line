#include "get_next_line.h"

char	*ft_read_file(int fd, char *str)
{
	char	*buf;
	int		byte;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	byte = 1;
	while (!ft_strchr(str, '\n') && byte != 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[byte] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_read_file(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_get_line(buf);
	buf = ft_new_str(buf);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int		i = 1;
	int		fd1;
	int		fd2;
	int		fd3;

	printf("-------------------\n");
	fd1 = open("test/test.txt", O_RDONLY);
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	fd2 = open("test/test2.txt", O_RDONLY);
	printf("\n-------------------\n-------------------\n");
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd2);
	fd3 = open("test/test3.txt", O_RDONLY);
	printf("\n-------------------\n-------------------\n");
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	printf("\n-------------------\n");
	close(fd3);
	return (0);
}
