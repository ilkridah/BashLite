/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:28:52 by ilkridah          #+#    #+#             */
/*   Updated: 2021/11/27 01:30:07 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_finder(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen((char *)s1);
	while (s1[start] && my_finder(s1[start], set))
		start++;
	while (start < end && my_finder(s1[end - 1], set))
		end--;
	i = 0;
	p = (char *)malloc(sizeof(char ) * (end - start + 1));
	if (!p)
		return (NULL);
	while (start < end)
		p[i++] = s1[start++];
	p[i] = '\0';
	return (p);
}
