/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:18:12 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/09 10:55:29 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	cd_error(void)
{
	ft_putstr_fd("cd : too many arguments\n", 2);
	g_exit_status = 1;
	return (g_exit_status);
}

char	*get_path(t_env *env)
{
	char	*path;
	t_env	*tmp;

	tmp = env;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->var_name, "HOME") == 0)
			break ;
		tmp = tmp->next;
	}
	path = ft_strdup(tmp->var_value);
	if (!path)
		return (NULL);
	return (path);
}

int	chdir_error(char *strerror, char *flag)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(strerror, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(flag, 2);
	ft_putchar_fd('\n', 2);
	g_exit_status = 1;
	return (g_exit_status);
}

void	update_pwds(t_env **env)
{
	char	*tmp_pwd;
	t_env	*tmp;

	tmp = *env;
	while (tmp->next)
	{
		if (ft_strcmp("PWD", tmp->var_name) == 0)
			break ;
		tmp = tmp->next;
	}
	tmp_pwd = ft_strdup(tmp->var_value);
	free(tmp->var_value);
	tmp->var_value = getcwd(NULL, 0);
	tmp = *env;
	while (tmp->next)
	{
		if (ft_strcmp("OLDPWD", tmp->var_name) == 0)
			break ;
		tmp = tmp->next;
	}
	free(tmp->var_value);
	tmp->var_value = ft_strdup(tmp_pwd);
	free(tmp_pwd);
}

int	cd(t_cmd *cmd, t_env **env)
{
	char	*path;

	if (cmd->info.flags)
	{
		if (cmd->info.flags[1])
			return (cd_error());
		else if (ft_strcmp(cmd->info.flags[0], "~") == 0)
			path = get_path(*env);
		else
			path = ft_strdup(cmd->info.flags[0]);
	}
	else
		path = get_path(*env);
	if (chdir(path) != 0)
	{
		cmd->info.err_msg = ft_strdup(strerror(errno));
		free(path);
		return (chdir_error(cmd->info.err_msg, cmd->info.flags[0]));
	}
	free(path);
	update_pwds(env);
	g_exit_status = 0;
	return (g_exit_status);
}
