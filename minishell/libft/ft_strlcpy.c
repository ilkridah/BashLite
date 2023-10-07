/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:43:50 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/15 20:33:25 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (!dstsize)
	{
		return (ft_strlen(src));
	}
	while (src[i] != '\0' && (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
		dstsize--;
	}
	dest[i] = 0;
	return (ft_strlen(src));
}
