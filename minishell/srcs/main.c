/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:02:01 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/16 17:51:18 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	g_exit_status;

void	complete_parsing(t_data *data)
{
	expander(data, &data->token);
	quotes_proc(data);
	creating_commands(data, data->token);
	if (data->cmd)
		execution(data);
	ft_free_struct(data);
}

int	reading_and_tokenization(t_data *data)
{
	aka_signal(0);
	data->line = readline("~ minishell > ");
	if (data->line == NULL)
	{
		write(1, "~ ADIOS ~\n", 10);
		exit(130);
	}
	add_history(data->line);
	if (ft_tokenize(data, data->line) != 0)
	{
		if (data->line)
		{
			free(data->line);
			data->line = NULL;
		}
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void) argv;
	envp_checker(envp);
	if (argc != 1)
		ft_putstr_fd("MUST BE!! : ./minishell\n", 2);
	else
	{
		ft_init(&data, envp);
		while (1)
		{
			if (reading_and_tokenization(&data) == 1)
			{
				ft_free_struct(&data);
				continue ;
			}
			if (collect_information(&data.token) == 1)
			{
				ft_free_struct(&data);
				continue ;
			}
			complete_parsing(&data);
		}
	}
	return (0);
}
