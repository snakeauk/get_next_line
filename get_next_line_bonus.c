#include "get_next_line_bonus.h"

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
	static char	*buf[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf[fd] = ft_read_file(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = ft_get_line(buf[fd]);
	buf[fd] = ft_new_str(buf[fd]);
	return (line);
}

