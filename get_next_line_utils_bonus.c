#include "get_next_line.h"

size_t  ft_strlen(char *s)
{
    size_t	count;

    if (!s)
        return (0);
    count = 0;
    while (s[count])
        count++;
    return (count);
}

char	*ft_strchr(char *s, int c)
{
    size_t	index;

    index = 0;
    if (!s)
        return (NULL);
    if (c == '\0')
        return ((char *)&s[ft_strlen(s)]);
    while (s[index])
    {
        if ((unsigned char)s[index] == (unsigned char) c)
            return ((char *)&s[index]);
        index++;
    }
    return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
    size_t	index;
    size_t	s1_len;
    size_t	s2_len;
    char	*str;

    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char));
        if (!s1)
            return (0);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    str = malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (str == NULL)
        return (NULL);
    index = 0;
    if (s1)
    {
        while (s1[index])
        {
            str[index] = s1[index];
            index++;
        }
    }
    index = 0;
    while (s2[index])
    {
        str[s1_len + index] = s2[index];
        index++;
    }
    str[s1_len + index] = '\0';
    free(s1);
    return (str);
}

char	*ft_get_line(char *str)
{
    size_t  index;
    size_t  n_flag;
    char    *buf;

    index = 0;
    if (!str[index])
        return (NULL);
    while (str[index] && str[index] != '\n')
    {
        index++;
    }
    n_flag = 0;
    if (str[index] == '\n')
        n_flag = 1;
    buf = (char *)malloc(sizeof(char) * (index + n_flag + 1));
    if (!buf)
        return (NULL);
    index = 0;
    while (str[index] && str[index] != '\n')
    {
        buf[index] = str[index];
        index++;
    }
    if (n_flag)
    {
        buf[index] = str[index];
        index++;
    }
    buf[index] = '\0';
    return (buf);
}

char	*ft_next_str(char *str)
{
    size_t  index;
    size_t  size;
    char		*buf;

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
        free(str);
        return (NULL);
    }
    index++;
    size = 0;
    while (str[index])
    {
        buf[size] = str[index];
        size++;
        index++;
    }
    buf[size] = '\0';
    free(str);
    return (buf);
}
