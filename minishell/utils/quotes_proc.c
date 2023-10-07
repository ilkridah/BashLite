/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:13:16 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/15 11:44:33 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	skip_quotes(t_token **token)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * count_len_quotes((*token)->str, i, i));
	if (!new)
		return (1);
	while ((*token)->str[i])
	{
		if (if_default(token, i) == 1)
		{
			change_to_quote(token, &i);
			continue ;
		}
		else if (change_to_default(token, &i) == 1)
			continue ;
		new[j++] = (*token)->str[i++];
	}
	new[j] = '\0';
	free((*token)->str);
	(*token)->str = new;
	return (0);
}

int	quotes_proc(t_data *data)
{	
	t_token	*token;
	int		i;

	i = 0;
	token = data->token;
	while (token)
	{
		if (check_quotes(token->str) == 1)
			skip_quotes(&token);
		token = token->next;
	}
	return (0);
}
