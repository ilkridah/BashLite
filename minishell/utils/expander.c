/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:10:51 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/16 17:45:11 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	fill_if_not_exists(t_token **list, char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = 0;
	j = 0;
	len = ft_strlen(str) - count_len(str);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (1);
	while (str[i])
	{
		if (str[i] == '$')
		{
			i = i + count_len(str) + 1;
			if (str[i] == '\0')
				break ;
		}
		new[j++] = str[i++];
	}
	new[j] = '\0';
	free ((*list)->str);
	(*list)->str = new;
	return (0);
}

void	copy_value(char *new, char *value, int *j)
{
	int	f;

	f = 0;
	while (value[f])
	{
		new[*j] = value[f];
		f++;
		(*j)++;
	}
}

int	fill_if_exists(t_token **list, char *str, char *var_val)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	i = 0;
	new = malloc(sizeof(char) * ft_strlen(str) - count_len(str) \
			+ ft_strlen(var_val));
	if (!new)
		return (1);
	while (str[i])
	{
		if (str[i] == '$')
		{
			copy_value(new, var_val, &j);
			i = i + count_len(str) + 1;
			if (str[i] == '\0')
				break ;
		}
		new[j++] = str[i++];
	}
	new[j] = '\0';
	free ((*list)->str);
	(*list)->str = new;
	return (0);
}

int	fill_var(t_token **list, char *value)
{
	if (value == NULL)
	{
		if (fill_if_not_exists(list, (*list)->str) == 1)
		{
			free(value);
			return (1);
		}
	}
	else
	{
		if (fill_if_exists(list, (*list)->str, value) == 1)
		{
			free(value);
			return (1);
		}
	}
	return (0);
}

int	expander(t_data *data, t_token **token)
{
	t_token	*list;
	int		i;

	list = *token;
	while (list)
	{
		if (list->type == HEREDOC)
			list = list->next->next;
		if (list->type == VAR)
		{
			i = 0;
			while (list->str[i])
			{
				if (list->str[i] == '$' && check_next(list->str[i + 1]) == 0 \
					&& check_dollar_quotes(list->str, i) == 0)
					fill_var(&list, var_val(list->str, data));
				else
				i++;
			}
		}
		list = list->next;
	}
	return (0);
}
