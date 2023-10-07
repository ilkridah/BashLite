/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:04:26 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/16 18:29:17 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	quotes_error(void)
{
	ft_putstr_fd("minishell: quotes are not closed\n", 2);
	g_exit_status = 127;
	return (1);
}

int	ft_tokenize(t_data *data, char *line)
{
	int	len;
	int	start;
	int	status;
	int	i;

	i = 0;
	start = 0;
	status = 0;
	len = ft_strlen(line);
	while (i <= len)
	{
		status = check_status(status, line, i);
		if (status == 0)
		{
			start = stock_word_and_sep(&i, line, start, data);
		}
		i++;
	}
	if (status != 0)
		return (quotes_error());
	return (0);
}
