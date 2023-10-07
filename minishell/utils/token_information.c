/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_information.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:04:39 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/17 10:32:38 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	token_error(char *str)
{
	printf("syntax error near unexpected token `%s'\n", str);
	return (1);
}

void	var_infos(t_token **token)
{
	int	i;

	i = 0;
	while ((*token)->str[i])
	{
		if ((*token)->str[i] == '$')
		{
			if ((*token)->str[i + 1] && (*token)->str[i + 1] == '?')
				break ;
			if ((*token)->prev && (*token)->prev->type == HEREDOC)
				break ;
			(*token)->type = VAR;
			break ;
		}
		i++;
	}
}

int	ft_check_cases(t_token **list)
{
	t_token	*token;

	token = *list;
	while (token)
	{
		if (token->next)
		{
			if (token->type >= PIPE && token->next->type == END)
				return (token_error(token->str));
			if (token->type > PIPE && token->next
				&& (token->next->type != WORD && token->next->type != VAR))
				return (token_error(token->str));
		}
		token = token->next;
	}
	return (0);
}

int	collect_information(t_token **list)
{
	t_token	*token;

	token = *list;
	if (token->type == PIPE)
		return (token_error(token->str));
	while (token)
	{
		var_infos(&token);
		if (ft_check_cases(&token) == 1)
			return (1);
		token = token->next;
	}
	return (0);
}
