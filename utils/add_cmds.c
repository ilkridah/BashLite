/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:23:00 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/16 17:40:44 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

t_cmd	*ft_lstnew_cmd(int val)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_cmd));
	new->is_pip = val;
	new->info.fd_out = 1;
	return (new);
}

void	ft_lstadd_back_cmd(t_cmd **list, t_cmd *new)
{
	t_cmd	*start;

	start = *list;
	if (start == NULL)
	{
		*list = new;
		return ;
	}
	if (*list && new)
	{
		while (start->right != NULL)
			start = start->right;
		start->right = new;
		start->left = start;
	}
}

t_cmd	*last_cmd(t_cmd *cmd)
{
	while (cmd->right != NULL)
		cmd = cmd->right;
	return (cmd);
}

void	add_cmd(t_cmd *cmd, char *str)
{
	cmd->info.cmd = str;
	if (!ft_strncmp("echo", str, 4)
		|| !ft_strncmp("cd", str, 2)
		|| !ft_strncmp("pwd", str, 3)
		|| !ft_strncmp("export", str, 6)
		|| !ft_strncmp("unset", str, 5)
		|| !ft_strncmp("env", str, 3)
		|| !ft_strncmp("exit", str, 4))
			cmd->info.builtin = true;
}

void	words_parsing(t_cmd **cmd, t_token **list)
{
	t_token	*tmp;
	t_cmd	*last;

	tmp = *list;
	last = last_cmd(*cmd);
	if ((tmp->prev && tmp->prev->type == PIPE) || last->info.cmd == NULL)
	{
		add_cmd(last, tmp->str);
		tmp = tmp->next;
	}
	else
		creat_flags(&tmp, last);
	*list = tmp;
}
