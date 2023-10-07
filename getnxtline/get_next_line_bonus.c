/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:52:36 by ilkridah          #+#    #+#             */
/*   Updated: 2021/12/19 19:06:13 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readline(char *str, int fd)
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

char	*ft_check(int fd, char *str)
{
	if (fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_readline(str, fd);
	if (!str)
		return (NULL);
	return (str);
}

char	*get_rest(char *str)
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
	static char	*str[10240];
	char		*line;

	str[fd] = ft_check(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	if (ft_strlen(str[fd]) > 0 && !ft_strchr(str[fd], '\n'))
	{
		line = ft_strdup(str[fd]);
		ft_free(&str[fd]);
		return (line);
	}
	else if (ft_strchr(str[fd], '\n'))
	{
		line = ft_substr(str[fd], 0, ft_strchr(str[fd], '\n') - str[fd] + 1);
		if (*(ft_strchr(str[fd], '\n') + 1) != '\0')
			str[fd] = get_rest(str[fd]);
		else
			ft_free(&str[fd]);
		return (line);
	}
	ft_free(&str[fd]);
	return (0);
}
