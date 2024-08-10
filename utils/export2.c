/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:47:02 by ilkridah          #+#    #+#             */
/*   Updated: 2022/09/14 21:52:24 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	export_no_flag(t_cmd *cmd, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	export_sort(*env);
	if (!cmd->info.flags)
	{
		while (tmp)
		{
			ft_putstr_fd("export ", cmd->info.fd_out);
			ft_putstr_fd(tmp->var_name, cmd->info.fd_out);
			if (ft_strchr(tmp->line, '='))
			{
				ft_putstr_fd("=\"", cmd->info.fd_out);
				ft_putstr_fd(tmp->var_value, cmd->info.fd_out);
				ft_putstr_fd("\"\n", cmd->info.fd_out);
			}
			else
				ft_putchar_fd('\n', cmd->info.fd_out);
			tmp = tmp->next;
		}
	}
}

int	if_valid(char *line)
{
	if (line[0] >= '0' && line[0] <= '9')
		return (0);
	if (line[0] == '=' || (line[0] == '$' && line[1] == '?'))
		return (0);
	return (1);
}

int	if_already_exported(t_env *env, char *var)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->var_name, var) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_env	*ft_new_node(char *line, char *name, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!(new))
		return (NULL);
	new->line = line;
	new->var_name = name;
	new->var_value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_add_back_node(t_env **env, t_env *new_node)
{
	t_env	*start;

	start = *env;
	if (start == NULL)
	{
		*env = new_node;
		return ;
	}
	if (env && *env && new_node)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new_node;
		new_node->prev = start;
	}
}
