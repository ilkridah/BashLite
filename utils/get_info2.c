/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:48:11 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/11 18:02:58 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../incl/minishell.h"

char	*get_cmd_path(char **env, char *cmd)
{
	int		i;
	char	**tab;
	char	*path;

	if (strchr (cmd, '/'))
		return (ft_strdup(cmd));
	i = get_start(env);
	if (i == -1)
		return (NULL);
	tab = ft_split(env[i] + 5, ':');
	i = 0;
	while (tab[i] != NULL)
	{
		path = join_path(tab[i], cmd);
		if (access (path, X_OK) == 0)
		{
			free_tab(tab);
			return (path);
		}
		free(path);
		i++;
	}
	if (tab)
		free_tab(tab);
	return (NULL);
}

t_exec	*get_execve_infos(t_data *data, t_cmd *cmd)
{
	t_exec	*info;

	info = (t_exec *)malloc(sizeof(t_exec));
	if (!info)
		return (NULL);
	info->env_array = env_copy(data->env_copy);
	info->path = get_cmd_path(info->env_array, cmd->info.cmd);
	info->cmd_and_flags = creat_cmd(cmd);
	return (info);
}
