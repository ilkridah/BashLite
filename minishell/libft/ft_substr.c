/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:22:05 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/15 20:35:07 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen (s))
		p = (char *)malloc(sizeof(*s) * (len + 1));
	else
		p = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (s[start] && j < len)
			p[j++] = s[start++];
		i++;
	}
	p[j] = '\0';
	return (p);
}
