/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:55:38 by ilkridah          #+#    #+#             */
/*   Updated: 2021/11/27 01:30:02 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = NULL;
	while (*(char *)s != '\0')
	{
		if ((char)*s == (char) c)
			str = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (str);
}
