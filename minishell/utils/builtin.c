/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:59:10 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/11 20:28:59 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	close_fd_builtin(t_cmd *cmd)
{
	if (cmd->info.fd_in > STDIN_FILENO)
		close(cmd->info.fd_in);
	if (cmd->info.fd_out > STDOUT_FILENO)
		close(cmd->info.fd_out);
}

int	builtin_execution(t_data *data, t_cmd *cmd)
{
	if (ft_strcmp(cmd->info.cmd, "pwd") == 0)
		pwd(cmd, data->env_copy);
	if (ft_strcmp(cmd->info.cmd, "env") == 0)
		env(cmd, &data->env_copy);
	else if (ft_strcmp(cmd->info.cmd, "export") == 0)
		export(data, cmd, &data->env_export);
	else if (ft_strcmp(cmd->info.cmd, "echo") == 0)
		echo(cmd);
	else if (ft_strcmp(cmd->info.cmd, "cd") == 0)
		cd(cmd, &data->env_copy);
	else if (ft_strcmp(cmd->info.cmd, "unset") == 0)
		unset(data, cmd);
	else if (ft_strcmp(cmd->info.cmd, "exit") == 0)
		ft_exit(cmd);
	return (0);
}
