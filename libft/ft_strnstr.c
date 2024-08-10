/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:49:05 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/15 20:34:43 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	int	i;

	i = 0;
	if (tofind[i] == 0)
		return ((char *)&str[i]);
	while (*str && len)
	{
		if (str[i] == tofind[i])
		{
			i++;
			len--;
			if (tofind[i] == 0)
				return ((char *)(str));
		}
		else
		{
			len = i + len;
			str++;
			i = 0;
			len--;
		}
	}
	return (0);
}
