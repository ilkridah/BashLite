/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:44:42 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/09 11:04:03 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../incl/minishell.h"

void	del_env(t_env *env)
{
	if (env && env->line)
	{
		free(env->line);
		env->line = NULL;
	}
	if (env && env->var_name)
	{
		free(env->var_name);
		env->var_name = NULL;
	}
	if (env && env->var_value)
	{
		free(env->var_value);
		env->var_value = NULL;
	}
	if (env)
		free(env);
}

void	unset_env(t_env **env, char *var_to_del)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp->next)
	{
		if (ft_strcmp(var_to_del, tmp->var_name) == 0)
			break ;
		tmp = tmp->next;
	}
	if (tmp->prev)
	{
		tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
	}
	else
	{
		tmp->next->prev = NULL;
		*env = tmp->next;
	}
	del_env(tmp);
}

int	grep_var(t_env *env, char *var)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(var, tmp->var_name) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	unset(t_data *data, t_cmd *cmd)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	if (!cmd->info.flags)
		return (0);
	while (cmd->info.flags[i])
	{
		if (if_valid(cmd->info.flags[i]) == 0)
			error = error_print(cmd->info.flags[i]);
		else if (grep_var(data->env_export, cmd->info.flags[i]) == 0)
		{
			unset_env(&data->env_export, cmd->info.flags[i]);
			if (grep_var(data->env_copy, cmd->info.flags[i]) == 0)
				unset_env(&data->env_copy, cmd->info.flags[i]);
		}
		i++;
	}
	if (error == 1)
		return (1);
	g_exit_status = 0;
	return (0);
}
