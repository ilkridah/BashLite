/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:56:12 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/14 22:44:11 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	builtin_with_pipe(t_cmd *cmd, t_data *data, int *tube)
{
	change_in_out(cmd, tube);
	builtin_execution(data, cmd);
}

void	exec_cmd(t_data *data, t_cmd *cmd, int *tube)
{
	data->pid = fork();
	if (data->pid < 0)
		return ;
	else if (data->pid == 0)
	{
		child(data, cmd, tube);
	}
	else
		parent(cmd, tube);
}

int	execution(t_data *data)
{
	t_cmd	*cmd;
	int		tube[2];

	cmd = data->cmd;
	aka_signal(1);
	if (cmd->right == NULL && cmd->info.builtin == 1)
	{
		builtin_execution(data, cmd);
		close_fd_builtin(cmd);
	}
	else
	{
		while (cmd)
		{
			if (pipe(tube) == -1)
				return (-1);
			exec_cmd (data, cmd, tube);
			if (cmd->right)
				cmd = cmd->right->right;
			else
				cmd = cmd->right;
		}
		wait_and_close(data, data->cmd);
	}
	return (0);
}
