/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:25:49 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/16 17:38:43 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	check_next(char s)
{
	if (s == '$' || s == ' ' || s == '=' || s == '0')
		return (1);
	else
		return (0);
}

int	check_dollar_quotes(char *str, int i)
{
	if (i > 1)
	{
		if (str[i - 2] == '\"')
			return (0);
		if (str[i - 2] == '\'')
			return (1);
	}
	if (i > 0)
	{
		if (str[i - 1] == '\'')
			return (1);
		else
			return (0);
	}
	return (0);
}

int	check_cases(char s)
{
	if (s == ' ' || s == '$' || s == '\0' || s == '\'' || s == '\"'
		|| (s >= '\t' && s <= '\r')
		|| s == '=' || s == '[' || s == ']' || s == '{' || s == '}')
		return (0);
	else
		return (1);
}

int	count_len(char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i] != '$')
		i++;
	i++;
	if (str[i] >= '0' && str[i] <= '9')
		return (len + 1);
	while (str[i])
	{
		if (check_cases(str[i]) == 0)
			break ;
		i++;
		len++;
	}
	return (len);
}

char	*join_var(char *str)
{
	char	*nvar;
	int		start;
	int		i;
	int		len;

	start = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			start = i + 1;
			break ;
		}
		i++;
	}
	len = count_len(str);
	nvar = ft_substr(str, start, len);
	if (!nvar)
		return (NULL);
	nvar = ft_strjoin(nvar, "=");
	return (nvar);
}
