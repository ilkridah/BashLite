/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:04:17 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/12 12:54:55 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

char	*find_name(char *line)
{
	char	*name;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			break ;
		i++;
	}
	return (name = ft_substr(line, 0, i));
}

char	*find_val(char *line)
{
	char	*var_value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '=')
			j = i + 1;
		i++;
	}
	return (var_value = ft_substr(line, j, j - i));
}

t_env	*stock_envp(char **envp)
{
	t_env	*list;
	char	*line;
	char	*var_name;
	char	*var_value;
	int		i;

	i = 0;
	list = NULL;
	while (envp[i])
	{
		line = ft_strdup(envp[i]);
		var_name = find_name(line);
		var_value = find_val(line);
		ft_lstadd_back(&list, ft_lstnew_node(line, var_name, var_value));
		i++;
	}
	return (list);
}

int	ft_init(t_data *data, char **envp)
{
	data->envp = envp;
	data->env_copy = stock_envp(envp);
	data->env_export = stock_envp(envp);
	data->token = NULL;
	return (0);
}
