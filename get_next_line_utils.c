#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  count;

    if (!s)
        return (0);
    count = 0;
    while (s[count])
        count++;
    return (count);
}

char    *ft_strchr(const char *s, int c)
{
    size_t  index;

    if (!s)
        return (NULL);
    index = 0;
    while (s[index])
    {
        if (s[index] == (char)c)
            return ((char *)&s[index]);
        index++;
    }
    if ((unsigned char)s[index] == (unsigned char)c)// when c='\0'
        return ((char *)&s[index]);
    return (NULL);
}

char  *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    size_t  len;
    size_t  size;
    size_t  index;

    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char) * 1);
        if (!s1)
        {
            free(s1);
            return (NULL);
        }
        s1[0] = '\0';
    }
    if (!s2)
        return (NULL);
    len = ft_strlen(s1);
    size = ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (len + size + 1));
    if (!str)
    {
        free(str);
        return (NULL);
    }
    index = -1;
    while (s1[++index])
        str[index] = s1[index];
    index = -1;
    while (s2[++index])
        str[len + index] = s2[index];
    str[len + index] = '\0';
    free(s1);
    return (str);
}

char  *ft_get_line(char *str)
{
    char    *buf;
    size_t  index;

    if (!str)
        return (NULL);
    index = 0;
    while (str[index] && str[index] != '\n')
        index++;
    buf = (char *)malloc(sizeof(char) * (index + 2));
    if (!buf)
    {
        free(buf);
        return (NULL);
    }
    index = 0;
    while (str[index] && str[index] != '\n')
    {
        buf[index] = str[index];
        index++;
    }
    if (str[index] == '\n')
    {
        buf[index] = '\n';
        index++;
    }
    buf[index] = '\0';
    return (buf);
}

char  *ft_next_str(char *str)
{
    char    *buf;
    size_t  index;
    size_t  size;
    
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
        free(buf);
        return (NULL);
    }
    index++;
    size = 0;
    while (str[index + size])
    {
        buf[size] = str[index + size];
        size++;
    }
    buf[size] = '\0';
    free(str);
    return (buf);
}

