/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:50:36 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/11 18:05:28 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	parent(t_cmd *cmd, int *tube)
{
	close(tube[1]);
	if (cmd->info.fd_in > STDIN_FILENO)
		close(cmd->info.fd_in);
	if (cmd->right && cmd->right->right->info.fd_in == STDIN_FILENO)
		cmd->right->right->info.fd_in = tube[0];
	else
		close(tube[0]);
	return ;
}
