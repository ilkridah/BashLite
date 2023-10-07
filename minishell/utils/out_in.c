/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 07:11:51 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/02 07:14:09 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	print_error(t_cmd *cmd, char *file)
{
	cmd->info.error = errno;
	cmd->info.err_msg = ft_strdup(strerror(errno));
	printf("ERROR : %s : %s\n", file, cmd->info.err_msg);
}

void	parsing_redir_in(t_cmd **cmd, t_token **tokens)
{
	t_token	*tmp;
	t_cmd	*last;
	int		fd;

	tmp = *tokens;
	last = last_cmd(*cmd);
	if (last->info.cmd && ft_strncmp(last->info.cmd, "echo", 4) == 0)
	{
		*tokens = tmp->next->next;
		return ;
	}
	last->info.redir_in = 1;
	fd = open(tmp->next->str, O_RDWR, S_IRWXU);
	if (fd == -1)
		print_error(last, tmp->next->str);
	last->info.fd_in = fd;
	if (tmp->next->next)
		tmp = tmp->next->next;
	*tokens = tmp;
}

void	parsing_redir_out(t_cmd **cmd, t_token **tokens)
{
	t_token	*tmp;
	t_cmd	*last;
	int		fd;

	tmp = *tokens;
	last = last_cmd(*cmd);
	last->info.redir_out = 1;
	if (last->info.fd_in != 1)
	{
		fd = open(tmp->next->str, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
		if (fd == -1)
			print_error(last, tmp->next->str);
		last->info.fd_out = fd;
	}
	if (tmp->next->next)
		tmp = tmp->next->next;
	*tokens = tmp;
}

void	parsing_append(t_cmd **cmd, t_token **tokens)
{
	t_token	*tmp;
	t_cmd	*last;
	int		fd;

	tmp = *tokens;
	last = last_cmd(*cmd);
	last->info.redir_out = 1;
	fd = open(tmp->next->str, O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
	if (fd == -1)
		print_error(last, tmp->next->str);
	last->info.fd_out = fd;
	if (tmp->next->next)
		tmp = tmp->next->next;
	*tokens = tmp;
}
