/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:21:21 by ikharbac          #+#    #+#             */
/*   Updated: 2022/08/25 19:26:41 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	check_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int	count_len_quotes(char *str, int count, int i)
{
	int	state;

	state = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && state == 0)
		{
			if (str[i] == '\'')
				state = 1;
			if (str[i] == '\"')
				state = 2;
			i++;
			continue ;
		}
		else if ((str[i] == '\'' && state == 1)
			|| (str[i] == '\"' && state == 2))
		{
			state = 0;
			i++;
			continue ;
		}
		count++;
		i++;
	}
	return (count + 1);
}

int	if_default(t_token **token, int i)
{
	if (((*token)->str[i] == '\'' || (*token)->str[i] == '\"')
		&& (*token)->state == 0)
		return (1);
	else
		return (0);
}

void	change_to_quote(t_token **token, int *i)
{
	if ((*token)->str[*i] == '\'')
			(*token)->state = 1;
	if ((*token)->str[*i] == '\"')
			(*token)->state = 2;
	(*i)++;
}

int	change_to_default(t_token **token, int *i)
{
	if (((*token)->str[*i] == '\'' && (*token)->state == 1)
		|| ((*token)->str[*i] == '\"' && (*token)->state == 2))
	{
		(*token)->state = 0;
		(*i)++;
		return (1);
	}
	else
		return (0);
}
