/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:45:50 by ilkridah          #+#    #+#             */
/*   Updated: 2021/12/18 18:45:30 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_readline(char *str, int fd)
{
	int		b;
	char	*temp;
	char	buff[BUFFER_SIZE + 1];

	b = 1;
	if (!str)
		str = ft_strdup("");
	while (!ft_strchr(str, '\n') && (b != 0))
	{
		b = read(fd, buff, BUFFER_SIZE);
		if (b == -1)
		{
			free(str);
			str = NULL;
			return (0);
		}
		buff[b] = '\0';
		temp = str;
		str = ft_strjoin(str, buff);
		free(temp);
	}
	return (str);
}

static char	*ft_check(int fd, char *str)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_readline(str, fd);
	if (!str)
		return (NULL);
	return (str);
}

static char	*get_rest(char *str)
{
	char	*rest;

	rest = ft_strdup(ft_strchr(str, '\n') + 1);
	free(str);
	return (rest);
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = ft_check(fd, str);
	if (!str)
		return (NULL);
	if (ft_strlen(str) > 0 && !ft_strchr(str, '\n'))
	{
		line = ft_strdup(str);
		ft_free(&str);
		return (line);
	}
	else if (ft_strchr(str, '\n'))
	{
		line = ft_substr(str, 0, ft_strchr(str, '\n') - str + 1);
		if (*(ft_strchr(str, '\n') + 1) != '\0')
			str = get_rest(str);
		else
			ft_free(&str);
		return (line);
	}
	ft_free(&str);
	return (0);
}
