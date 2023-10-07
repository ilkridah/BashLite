/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:21:31 by ilkridah          #+#    #+#             */
/*   Updated: 2021/12/16 23:40:47 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s))
			len = ft_strlen((char *)s);
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (start < (size_t)ft_strlen((char *)s) && s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (unsigned char)c))
	{
		s++;
	}
	if (*s == (unsigned char)c)
	{
		return ((char *)s);
	}
	return ((char *) NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;

	if (s1 != NULL && s2 != NULL )
		i = (ft_strlen(s1)) + (ft_strlen(s2));
	else
		return (0);
	p = (char *)malloc(i + 1);
	if (!p)
		return (0);
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (p - i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (src[len])
	{
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
