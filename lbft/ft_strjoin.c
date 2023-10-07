/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:52:40 by ilkridah          #+#    #+#             */
/*   Updated: 2021/11/27 01:22:09 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join(char const *dest, char const *src, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		str[i] = dest[i];
		i++;
	}
	while (src[j] != '\0')
	{
		str[i + j] = src[j];
		j++;
	}
	str[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	total;

	if (!s1 || !s2)
		return (0);
	total = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(total + 1);
	if (!str)
		return (NULL);
	join(s1, s2, str);
	return (str);
}
