/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:04:23 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/17 10:23:48 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	check_status(int status, char *line, int i)
{
	if (line[i] == '\'' && status == 0)
		status = 1;
	else if (line[i] == '\'' && status == 1)
		status = 0;
	else if (line[i] == '\"' && status == 0)
		status = 2;
	else if (line[i] == '\"' && status == 2)
		status = 0;
	return (status);
}

int	type_of_separator(char *line, int index)
{
	if ((line[index] > 8 && line[index] < 14) || line[index] == 32)
		return (BLANK);
	else if (line[index] == '|')
		return (PIPE);
	else if (line[index] == '<' && line[index + 1] == '<')
		return (HEREDOC);
	else if (line[index] == '>' && line[index + 1] == '>')
		return (APPEND);
	else if (line[index] == '<')
		return (REDIR_IN);
	else if (line[index] == '>')
		return (REDIR_OUT);
	else if (line[index] == '\0')
		return (END);
	else
		return (0);
}

int	add_word(t_token **list, char *line, int index, int start)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (index - start + 1));
	if (!word)
		return (1);
	while (start < index)
	{
		word[i++] = line[start++];
	}
	word[i] = '\0';
	ft_add_back_token(list, ft_new_token(word, 2, 0));
	return (0);
}

int	add_separator(t_token **list, char *line, int index, int sign)
{
	char	*separator;
	int		i;

	i = 0;
	if (sign == APPEND || sign == HEREDOC)
	{
		separator = malloc(sizeof(char) * 3);
		if (!separator)
			return (1);
		while (i < 2)
			separator[i++] = line[index++];
		separator[i] = '\0';
		ft_add_back_token(list, ft_new_token(separator, sign, 0));
	}
	else
	{
		separator = malloc(sizeof(char) * 2);
		if (!separator)
			return (1);
		while (i < 1)
			separator[i++] = line[index++];
		separator[i] = '\0';
		ft_add_back_token(list, ft_new_token(separator, sign, 0));
	}
	return (1);
}

int	stock_word_and_sep(int *i, char *line, int start, t_data *data)
{
	int	sign;

	sign = type_of_separator(line, *i);
	if (sign)
	{
		if ((*i) != 0 && type_of_separator(line, (*i) - 1) == 0)
		{
			add_word(&data->token, line, *i, start);
		}
		if (sign == APPEND || sign == HEREDOC || sign == PIPE
			|| sign == REDIR_IN || sign == REDIR_OUT || sign == END)
		{
			add_separator(&data->token, line, *i, sign);
			if (sign == HEREDOC || sign == APPEND)
				(*i)++;
		}
		start = *i + 1;
	}
	return (start);
}
