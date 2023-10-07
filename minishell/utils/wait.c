/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:53:16 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/11 17:53:56 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

static void	exit_status(int status)
{
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_exit_status = WTERMSIG(status) + 128;
	else if (WIFSTOPPED(status))
		g_exit_status = WSTOPSIG(status) + 128;
}

void	wait_and_close(t_data *data, t_cmd *cmd)
{
	t_cmd	*tmp;
	int		status;
	int		pid;

	tmp = cmd;
	while (tmp)
	{
		pid = waitpid(0, &status, 0);
		if (pid == data->pid)
			exit_status(status);
		if (tmp->info.fd_out > STDOUT_FILENO)
			close(tmp->info.fd_out);
		if (tmp->info.fd_in > STDIN_FILENO)
			close(tmp->info.fd_in);
		if (tmp->right)
			tmp = tmp->right->right;
		else
			tmp = tmp->right;
	}
}
