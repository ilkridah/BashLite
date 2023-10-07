/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:34:30 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/16 17:50:32 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	envp_checker(char **envp)
{
	if (*envp == NULL)
	{
		ft_putstr_fd("ERROR : no environment", 2);
		exit(1);
	}
	g_exit_status = 0;
	return (0);
}

int	env(t_cmd *cmd, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	export_sort(*env);
	if (cmd->info.flags)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(cmd->info.flags[0], 2);
		ft_putstr_fd(" : No such file or directory\n", 2);
		g_exit_status = 127;
		return (g_exit_status);
	}
	while (tmp)
	{
		write(cmd->info.fd_out, tmp->var_name, ft_strlen(tmp->var_name));
		write(cmd->info.fd_out, "=", 1);
		write(cmd->info.fd_out, tmp->var_value, ft_strlen(tmp->var_value));
		write(cmd->info.fd_out, "\n", 1);
		tmp = tmp->next;
	}
	g_exit_status = 0;
	return (g_exit_status);
}
