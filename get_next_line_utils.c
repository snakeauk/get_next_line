/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:48:08 by kinamura          #+#    #+#             */
/*   Updated: 2024/05/04 18:47:17 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
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
		if ((unsigned char)s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (0);
}

char	*ft_strndup(char *s1, size_t n)
{
	char	*str;
	size_t	size;
	size_t	index;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (s1[index] && index < n)
	{
		str[index] = s1[index];
		index++;
	}
	str[size] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize > 0)
	{
		while (src[index] && index < (dstsize - 1))
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	while (src[index])
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		s1 = ft_strndup("\0", 1);
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&str[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	free(s1);
	return (str);
}
