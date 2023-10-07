/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:25:46 by ilkridah          #+#    #+#             */
/*   Updated: 2021/11/27 15:48:31 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	i = 0;
	slen = ft_strlen((char *)src);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen || dstsize == 0)
		return (slen + dstsize);
	else
		slen = slen + dlen;
	while ((src[i]) && (dlen < dstsize - 1))
	{
		dst[dlen] = src[i];
		i++;
		dlen++;
	}
	dst[dlen] = '\0';
	return (slen);
}
