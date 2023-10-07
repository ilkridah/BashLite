/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:44:14 by ilkridah          #+#    #+#             */
/*   Updated: 2022/09/15 20:21:05 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	export_var(t_env **env, char *line, char *var, char *val)
{
	t_env	*tmp;

	tmp = *env;
	if (if_already_exported(*env, var) == 1)
		ft_add_back_node(env, ft_new_node(line, var, val));
	else
	{
		while (tmp->next)
		{
			if (ft_strcmp(var, tmp->var_name) == 0)
				break ;
			tmp = tmp->next;
		}
		free(tmp->line);
		if (tmp->var_value)
			free(tmp->var_value);
		tmp->line = line;
		tmp->var_value = val;
		free(var);
	}
}

void	free_var_val(char *var, char *val)
{
	free(val);
	free(var);
}

void	replace_var(t_env *tmp, char *line, char *var, char *val)
{
	free(tmp->line);
	free(tmp->var_value);
	tmp->line = ft_strdup(line);
	tmp->var_value = val;
	free(var);
}

void	add_var_to_env(t_data *data, char *line, char *var, char *value)
{
	t_env	*tmp;

	tmp = data->env_copy;
	export_var(&data->env_export, ft_strdup(line), ft_strdup(var), \
	ft_strdup(value));
	if (ft_strchr(line, '=') == NULL)
		return (free_var_val(var, value));
	if (if_already_exported(data->env_copy, var) == 1)
		ft_add_back_node(&data->env_copy, ft_new_node(ft_strdup(line), \
		var, value));
	else
	{
		while (tmp->next)
		{
			if (ft_strcmp(var, tmp->var_name) == 0)
				break ;
			tmp = tmp->next;
		}
		replace_var(tmp, line, var, value);
	}
}

int	export(t_data *data, t_cmd *cmd, t_env **env)
{
	int	i;
	int	error;

	i = 0;
	export_no_flag(cmd, env);
	while (cmd->info.flags && cmd->info.flags[i])
	{
		if (if_valid(cmd->info.flags[i]) == 1)
		{
			add_var_to_env(data, cmd->info.flags[i], \
			find_name(cmd->info.flags[i]), \
			find_val(cmd->info.flags[i]));
		}
		else
			error = error_print(cmd->info.flags[i]);
		i++;
	}
	g_exit_status = 0;
	return (0);
}
