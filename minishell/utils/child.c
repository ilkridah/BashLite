/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:32:29 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/11 18:20:50 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	change_in_out(t_cmd *cmd, int *tube)
{
	close(tube[0]);
	if (cmd->info.builtin == 0 && cmd->info.fd_in > STDIN_FILENO)
	{
		dup2(cmd->info.fd_in, STDIN_FILENO);
		close(cmd->info.fd_in);
	}
	if (cmd->info.fd_out > STDOUT_FILENO)
	{
		dup2(cmd->info.fd_out, STDOUT_FILENO);
		close(cmd->info.fd_out);
	}
	else if (cmd->right != NULL)
	{
		dup2(tube[1], STDOUT_FILENO);
	}
	close(tube[1]);
}

char	**creat_cmd(t_cmd *cmd)
{
	char	**new;
	int		i;

	i = 0;
	while (cmd->info.flags && cmd->info.flags[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	new[i] = ft_strdup(cmd->info.cmd);
	while (cmd->info.flags && cmd->info.flags[i])
	{
		new[i + 1] = ft_strdup(cmd->info.flags[i]);
		i++;
	}
	new[i + 1] = NULL;
	return (new);
}

void	execute_cmd(t_cmd *cmd, int *tube, t_exec *exec)
{
	change_in_out(cmd, tube);
	execve(exec->path, exec->cmd_and_flags, exec->env_array);
	if (ft_strchr(cmd->info.cmd, '/'))
	{
		ft_putstr_fd("bash: ", STDERR_FILENO);
		ft_putstr_fd(cmd->info.cmd, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	g_exit_status = 127;
}

void	error_cmd_not_found(t_cmd *cmd)
{
	write(STDERR_FILENO, cmd->info.cmd, ft_strlen(cmd->info.cmd));
	write(STDERR_FILENO, ": command not found\n", 20);
	g_exit_status = 127;
}

void	child(t_data *data, t_cmd *cmd, int *tube)
{
	t_exec	*exec;
	char	*path;
	char	**env;

	exec = NULL;
	env = env_copy(data->env_copy);
	path = get_cmd_path(env, cmd->info.cmd);
	if (cmd->info.error)
		g_exit_status = 1;
	else if (cmd->info.builtin == 1)
		builtin_with_pipe(cmd, data, tube);
	else if (path)
	{
		exec = get_execve_infos(data, cmd);
		execute_cmd(cmd, tube, exec);
	}
	else
		error_cmd_not_found(cmd);
	free_tab(env);
	free(path);
	exit(g_exit_status);
}
