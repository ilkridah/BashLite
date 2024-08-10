/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:20:32 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/15 23:03:57 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	creat_flag(t_token **tokens, t_cmd *cmd)
{
	int		i;
	t_token	*tmp;

	i = 0;
	tmp = *tokens;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		i++;
		tmp = tmp->next;
	}
	cmd->info.flags = (char **)(malloc(sizeof(char *) * (i +1)));
	if (!cmd->info.flags)
		return (1);
	tmp = *tokens;
	i = 0;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		cmd->info.flags[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	cmd->info.flags[i] = NULL;
	*tokens = tmp;
	return (0);
}

char	**copy_old_to_new(int len, char **new, t_cmd *cmd, t_token **token)
{
	int		i;
	t_token	*tmp;

	i = 0;
	tmp = *token;
	while (i < len)
	{
		new[i] = cmd->info.flags[i];
		i++;
	}
	while (tmp->type == WORD || tmp->type == VAR)
	{
		new[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	new[i] = NULL;
	return (new);
}

int	join_flags(t_token **tokens, t_cmd *cmd)
{
	int		i;
	int		len;
	char	**tab;
	t_token	*tmp;

	i = 0;
	len = 0;
	tmp = *tokens;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		i++;
		tmp = tmp->next;
	}
	while (cmd->info.flags[len])
		len++;
	tab = (char **)malloc(sizeof(char *) * (i + len +1));
	if (!tab)
		return (1);
	tab = copy_old_to_new(len, tab, cmd, tokens);
	free(cmd->info.flags);
	cmd->info.flags = tab;
	*tokens = tmp;
	return (0);
}

int	creat_flags(t_token **token, t_cmd *cmd)
{
	if (cmd && !(cmd->info.flags))
		return (creat_flag(token, cmd));
	else
	{
		return (join_flags(token, cmd));
	}
	return (0);
}
