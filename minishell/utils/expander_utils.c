/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:26:30 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/09 11:09:37 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	if_exist(t_data *data, char *var)
{
	int		i;
	int		len;
	t_env	*list;

	i = 0;
	len = ft_strlen(var);
	list = data->env_copy;
	while (list)
	{
		if (ft_strncmp(list->line, var, len) == 0)
			return (0);
		list = list->next;
	}
	return (1);
}

char	*collect_value(t_data *data, char *var)
{
	char	*str;
	int		i;
	int		len;
	t_env	*list;

	i = 0;
	len = ft_strlen(var);
	list = data->env_copy;
	while (list)
	{
		if (ft_strncmp(list->line, var, len) == 0)
			break ;
		i++;
		list = list->next;
	}
	str = ft_strdup(list->var_value);
	return (str);
}

char	*var_val(char *str, t_data *list)
{
	char	*nvar;
	char	*value;

	(void)value;
	(void)list;
	nvar = join_var(str);
	if (nvar && if_exist(list, nvar) == 0)
	{
		value = collect_value(list, nvar);
	}
	else
		value = NULL;
	free (nvar);
	return (value);
}
