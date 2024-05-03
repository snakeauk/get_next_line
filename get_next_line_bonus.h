#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef  BUFFER_SIZE
# define BUFFER_SIZE 256
#endif
#ifndef FD_MAX
# define FD_MAX 256
#endif

char    *get_next_line(int fd);
char    *ft_read_file(int fd, char *str);
size_t  ft_strlen(char *s);
char    *ft_strchr(char *s, int c);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_get_line(char *str);
char    *ft_next_str(char *str);

#endif
