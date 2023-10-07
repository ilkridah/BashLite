/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:34:15 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/15 20:25:22 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	p = malloc(count * size);
	if (!p)
	{
		return (0);
	}
	ft_bzero (p, count * size);
	return (p);
}
