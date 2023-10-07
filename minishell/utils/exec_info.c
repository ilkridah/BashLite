/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:35:49 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/16 17:44:40 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	env_len(t_env *env)
{
	int		len;
	t_env	*tmp;

	len = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	free_tab(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

char	*join_path(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '/';
	i++;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

int	get_start(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	**env_copy(t_env *env)
{
	int		i;
	t_env	*tmp;
	char	**tab;

	i = 0;
	tmp = env;
	tab = (char **)malloc(sizeof(char *) * (env_len(env) + 1));
	if (!tab)
		return (NULL);
	while (tmp)
	{
		tab[i] = ft_strdup(tmp->line);
		tmp = tmp->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
