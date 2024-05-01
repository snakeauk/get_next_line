#include "get_next_line.h"

char  *ft_read_file(int fd, char *str)
{
    char  *buf;
    int   size;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    size = 1;
    while (!ft_strchr(str, '\n') && size != 0)
    {
        size = read(fd, buf, BUFFER_SIZE);
        if (size == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[size] = '\0';
        str = ft_strjoin(str, buf);
    }
    free(buf);
    return (str);
}

char  *get_next_line(int fd)
{
    static char *str;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = ft_read_file(fd, str);
    if (!str)
        return (NULL);
    line = ft_get_line(str);
    str = ft_next_str(str);
    return (line);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// int main(void)
// {
//     char *line;
//     int fd;
//     int i = 1;
// 
//     fd = open("texts/text.txt", O_RDONLY);
//     while (i < 10)
//     {
//         printf("%d", i);
//         line = get_next_line(fd);
//         printf ("%s",line);
//         i++;
//     }
//     close(fd);
//     return (0);
// }
