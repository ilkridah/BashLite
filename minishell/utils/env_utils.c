/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:04:36 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/12 13:06:24 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

t_env	*ft_lstnew_node(char *line, char *name, char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->line = line;
	new->var_name = name;
	new->var_value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*start;

	start = *lst;
	if (start == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst && new)
	{
		while (start->next != NULL)
		{
			start = start->next;
		}
		start->next = new;
		new->prev = start;
	}
}
