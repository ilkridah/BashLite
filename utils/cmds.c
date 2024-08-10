/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 07:09:37 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/16 17:41:20 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	len_flags(t_token *tmp)
{
	int	i;

	i = 0;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	add_echo_flag(t_token **tokens, t_cmd *cmd)
{
	int		flags;
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = *tokens;
	flags = len_flags(tmp);
	cmd->info.flags = (char **)malloc(sizeof(char *) * (flags + 1));
	if (!cmd->info.flags)
		return (1);
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

int	parsing_heredoc(t_data *data, t_token **list)
{
	pid_t	pid;
	int		pip_fd[2];
	t_token	*tmp;

	if (pipe(pip_fd) == -1)
		return (1);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
		heredoc_child(pip_fd, list, data);
	else
		heredoc_parent(data, pip_fd);
	tmp = *list;
	if (tmp->next->next)
		tmp = tmp->next->next;
	*list = tmp;
	return (1);
}

void	creating_commands(t_data *data, t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	if (tmp->type == END)
		return ;
	while (tmp->next != NULL)
	{
		if (tmp == tokens)
			ft_lstadd_back_cmd(&data->cmd, ft_lstnew_cmd(0));
		if (tmp->type == WORD || tmp->type == VAR)
			words_parsing(&data->cmd, &tmp);
		else if (tmp->type == REDIR_IN)
			parsing_redir_in(&data->cmd, &tmp);
		else if (tmp->type == REDIR_OUT)
			parsing_redir_out(&data->cmd, &tmp);
		else if (tmp->type == HEREDOC)
			parsing_heredoc(data, &tmp);
		else if (tmp->type == APPEND)
			parsing_append(&data->cmd, &tmp);
		else if (tmp->type == PIPE)
			parsing_pipe(&data->cmd, &tmp);
		if (tmp->type == END)
			break ;
	}
}
