/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:36:43 by ilkridah          #+#    #+#             */
/*   Updated: 2021/11/27 14:59:48 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(char const *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			counter++;
		while (s[i] != c && s[i])
		i++;
	}
	return (counter);
}

static char	**ft_free(char **newstr)
{
	int	i;

	i = 0;
	while (newstr[i] != 0)
	{
		free(newstr[i]);
		i++;
	}
	free(newstr);
	return (0);
}

static char	*ft_word(char *str, char c)
{
	char	*newstr;
	int		k;

	k = 0;
	while (str[k] != '\0' && str[k] != c)
		k++;
	newstr = (char *)malloc(sizeof(char) * k + 1);
	if (!newstr)
		return (*ft_free(&newstr));
	k = 0;
	while (str[k] != '\0' && str[k] != c)
	{
		newstr[k] = str[k];
		k++;
	}
	newstr[k] = '\0';
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	char	**newstr;
	int		i;

	i = 0;
	if ((s == 0 && c == 0) || s == 0)
		return (0);
	newstr = (char **)malloc(sizeof(char *) * (counter((char *)s, c) + 1));
	if (!newstr)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			newstr[i] = ft_word((char *)s, c);
			i++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	newstr[i] = NULL;
	return (newstr);
}
