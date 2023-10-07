/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:28:23 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/09 10:55:39 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	pwd(t_cmd *cmd, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp->next)
	{
		if (ft_strcmp("PWD", tmp->var_name) == 0)
			break ;
		tmp = tmp->next;
	}
	write(cmd->info.fd_out, tmp->var_value, ft_strlen(tmp->var_value));
	write(cmd->info.fd_out, "\n", 1);
	g_exit_status = 0;
}
