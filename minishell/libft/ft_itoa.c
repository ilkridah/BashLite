/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:59:48 by ikharbac          #+#    #+#             */
/*   Updated: 2021/11/23 10:50:16 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i ++;
	}
	return (i);
}

static char	*to_string(char *p, int n, int len)
{
	int	k;

	k = 0;
	if (n < 0)
	{
		p[0] = '-';
		k++;
		n = n * -1;
	}
	while (n != 0)
	{
		p[len - 1] = (n % 10) + 48;
		n = n / 10;
		k++;
		len--;
	}
	p[k] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	int		i;
	int		k;
	char	*p;

	k = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_len(n);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (0);
	return (to_string(p, n, i));
}
