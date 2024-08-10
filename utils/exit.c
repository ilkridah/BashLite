/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:48:37 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/11 20:28:27 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	error_many(void)
{
	ft_putstr_fd("bash: exit: too many arguments\n", STDERR_FILENO);
	g_exit_status = 1;
	return (g_exit_status);
}

void	error_numeric(char *flag)
{
	ft_putstr_fd("bash: exit: ", STDERR_FILENO);
	ft_putstr_fd(flag, STDERR_FILENO);
	ft_putstr_fd(" : numeric argument required\n", STDERR_FILENO);
	g_exit_status = 2;
	exit(g_exit_status);
}

int	is_valid(char *flag)
{
	int	i;

	i = 0;
	if (flag[i] == '-' || flag[i] == '+')
		i++;
	while (flag[i])
	{
		if (!ft_isdigit(flag[i]))
			return (0);
		i++;
	}
	if (ft_strlen(flag) >= 20)
		return (0);
	return (1);
}

int	ft_exit(t_cmd *cmd)
{
	if (cmd->info.flags)
	{
		if (is_valid(cmd->info.flags[0]) == false)
			error_numeric(cmd->info.flags[0]);
		else if (cmd->info.flags[1])
			return (error_many());
		else
			g_exit_status = ft_atoi(cmd->info.flags[0]);
	}
	ft_putstr_fd("exit\n", 1);
	exit(g_exit_status);
	return (g_exit_status);
}
