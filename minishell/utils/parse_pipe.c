/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 07:42:56 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/02 07:46:02 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	parsing_pipe(t_cmd **cmd, t_token **tokens)
{
	t_cmd	*tmp;
	t_cmd	*last;

	tmp = last_cmd(*cmd);
	ft_lstadd_back_cmd(cmd, ft_lstnew_cmd(1));
	last = last_cmd(*cmd);
	tmp->right = last;
	last->left = tmp;
	last->right = NULL;
	ft_lstadd_back_cmd(&last, ft_lstnew_cmd(0));
	*tokens = (*tokens)->next;
}
