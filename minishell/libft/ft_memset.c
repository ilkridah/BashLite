/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:10:41 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/15 20:30:10 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t num)
{
	int				i;
	unsigned char	*k;

	i = 0;
	k = ptr;
	while (num)
	{
		k[i] = c;
		i++;
		num--;
	}
	return (ptr);
}
