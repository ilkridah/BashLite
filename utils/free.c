/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:04:52 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/11 20:26:03 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	free_token(t_data *data)
{
	t_token	*tmp;

	tmp = NULL;
	while (data->token != NULL)
	{
		tmp = data->token->next;
		if (data->token->str)
			free(data->token->str);
		free(data->token);
		data->token = tmp;
	}
}

void	fre_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	ft_del_cmd(t_cmd *cmd)
{
	if (cmd->info.err_msg)
		free(cmd->info.err_msg);
	if (cmd->info.flags)
		fre_tab(cmd->info.flags);
	free(cmd);
}

void	ft_free_cmd(t_cmd **cmd)
{
	while (*cmd != NULL)
	{
		ft_del_cmd(*cmd);
		*cmd = (*cmd)->right;
	}
}

void	ft_free_struct(t_data *data)
{
	if (data->token)
		free_token(data);
	if (data->line)
		free(data->line);
	if (data->cmd)
		ft_free_cmd(&data->cmd);
}
