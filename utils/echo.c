/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:40:09 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/09 11:08:10 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

char	*replace_exit_value(char *flags)
{
	char	*exit_value;
	char	*new;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	exit_value = ft_itoa(g_exit_status);
	len = ft_strlen(exit_value);
	new = malloc(sizeof(char) * (len + 1));
	while (exit_value[j])
		new[i++] = exit_value[j++];
	new[i] = '\0';
	free(flags);
	free(exit_value);
	return (new);
}

static int	check_new_line(char *str)
{
	int	i;

	i = 1;
	if (ft_strlen(str) < 2 || str[0] != '-' || str[1] != 'n')
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	echo(t_cmd *cmd)
{
	int		newline;
	int		len;
	int		i;

	newline = 1;
	i = 0;
	while (cmd->info.flags && cmd->info.flags[i]
		&& check_new_line(cmd->info.flags[i]) == 0)
	{
		newline = 0;
		i++;
	}
	while (cmd->info.flags && cmd->info.flags[i])
	{
		if (ft_strncmp(cmd->info.flags[i], "$?", 2) == 0)
			cmd->info.flags[i] = replace_exit_value(cmd->info.flags[i]);
		len = ft_strlen(cmd->info.flags[i]);
		write(cmd->info.fd_out, cmd->info.flags[i], len);
		write(cmd->info.fd_out, " ", 1);
		i++;
	}
	if (newline == 1)
		write(cmd->info.fd_out, "\n", 1);
	g_exit_status = 0;
}
