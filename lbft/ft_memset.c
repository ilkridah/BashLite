/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:02:09 by ilkridah          #+#    #+#             */
/*   Updated: 2021/11/27 01:09:54 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t	len)
{
	unsigned char	*x;

	x = (unsigned char *)b;
	while (len > 0)
	{
		*x = c;
		x++;
		len--;
	}
	return (b);
}
