/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:19:39 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/15 20:34:57 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_left(char const *s1, char const *set)
{
	int	l;
	int	i;

	i = 0;
	l = 0;
	while (set[l])
	{
		if (set[l] == s1[i])
		{
			i++;
			l = 0;
		}
		else
			l++;
	}
	return (i);
}

static int	ft_right(char const *s1, char const *set, int j)
{
	int	l;

	l = 0;
	while (set[l])
	{
		if (set[l] == s1[j])
		{
			j--;
			l = 0;
		}
		else
			l++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*p;
	int		j;
	int		l;

	l = 0;
	i = 0;
	if (s1 == NULL)
		return ((char *)s1);
	j = ft_strlen(s1) - 1;
	i = ft_left(s1, set);
	j = ft_right(s1, set, j);
	l = j - i + 1;
	if (l <= 0)
		return (ft_strdup("\0"));
	j = l;
	p = malloc(sizeof(*s1) * (l + 1));
	if (!p)
		return (0);
	while (l--)
		*p++ = s1[i++];
	*p = '\0';
	return (p - j);
}
