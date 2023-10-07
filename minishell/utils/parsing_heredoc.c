/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:57:25 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/14 22:44:38 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

char	*get_line(char *line, char *delimiter, char *str)
{
	while (line)
	{
		line = readline("> ");
		if (!line)
		{
			ft_putchar_fd('\n', 2);
			break ;
		}
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
			break ;
		if (!str)
			str = ft_strdup(line);
		else
		{
			str = ft_strjoin(str, "\n");
			str = ft_strjoin(str, line);
		}
		free(line);
	}
	if (str == NULL)
		return (ft_strdup("\n"));
	str = ft_strjoin(str, "\n");
	free (line);
	return (str);
}

void	heredoc_child(int *pipe_fd, t_token **list, t_data *data)
{
	char	*buff;
	char	*line;
	char	*delimiter;
	t_token	*tmp;

	aka_signal(3);
	tmp = *list;
	line = malloc(sizeof(char));
	delimiter = tmp->next->str;
	close(pipe_fd[0]);
	buff = get_line(line, delimiter, NULL);
	write(pipe_fd[1], buff, ft_strlen(buff) +1);
	free (buff);
	ft_free_struct(data);
	exit(g_exit_status);
}

void	heredoc_parent(t_data *data, int *pipe_fd)
{
	wait(NULL);
	close(pipe_fd[1]);
	data->cmd->info.fd_in = pipe_fd[0];
}
