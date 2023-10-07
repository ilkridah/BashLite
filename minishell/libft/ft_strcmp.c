/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:14:15 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/09 10:49:31 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str1[i] || str2[j]))
	{
		if (str1[i] != str2[j])
			return ((unsigned char )str1[i] - (unsigned char )str2[j]);
		i++;
		j++;
	}
	return (0);
}
