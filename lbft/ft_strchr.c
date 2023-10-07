/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:23:47 by ilkridah          #+#    #+#             */
/*   Updated: 2021/11/27 01:21:37 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
