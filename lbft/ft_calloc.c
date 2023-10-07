/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:58:52 by ilkridah          #+#    #+#             */
/*   Updated: 2021/11/27 01:09:03 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	j;
	void	*p;

	j = count * size;
	p = malloc(j);
	if (!p)
		return (0);
	ft_bzero(p, j);
	return (p);
}
