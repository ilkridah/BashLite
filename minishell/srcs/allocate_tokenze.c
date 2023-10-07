/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_tokenze.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:04:13 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/15 11:44:42 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

t_token	*ft_new_token(char *str, int type, int state)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->str = str;
	new->type = type;
	new->state = state;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_add_back_token(t_token **lst,	t_token *new)
{
	t_token	*start;

	start = *lst;
	if (start == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst && new)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new;
		start->prev = start;
	}
}
