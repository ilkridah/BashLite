/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:47:17 by ilkridah          #+#    #+#             */
/*   Updated: 2022/09/17 10:41:22 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	handle_ignore(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 130;
		write(1, "\n", 1);
	}
	else if (sig == SIGQUIT)
	{
		g_exit_status = 131;
		ft_putstr_fd("Quit\n", STDOUT_FILENO);
	}
}

void	handle_0(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 130;
		write(1, "\n", 1);
	}
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 1;
		write(1, "> \n", 3);
		exit(0);
	}
}

void	aka_signal(int action)
{
	if (action == 0)
	{
		signal(SIGINT, handle_0);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (action == 1)
	{
		signal(SIGINT, handle_ignore);
		signal(SIGQUIT, handle_ignore);
	}
	else if (action == 3)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handle_heredoc);
	}
}
