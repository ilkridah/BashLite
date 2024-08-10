/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:17:15 by ilkridah          #+#    #+#             */
/*   Updated: 2022/09/15 11:48:34 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

static	void	swaper(t_env *actual, t_env *next_node)
{
	char	*temp_line;
	char	*temp_var_name;
	char	*temp_var_value;

	temp_line = actual->line;
	temp_var_name = actual->var_name;
	temp_var_value = actual->var_value;
	actual->line = next_node->line;
	actual->var_name = next_node->var_name;
	actual->var_value = next_node->var_value;
	next_node->line = temp_line;
	next_node->var_name = temp_var_name;
	next_node->var_value = temp_var_value;
}

void	export_sort(t_env *env)
{
	t_env	*actual;
	t_env	*next_node;

	actual = env;
	while (actual != NULL)
	{
		next_node = actual;
		while (next_node != NULL)
		{
			if (actual->var_name[0] > next_node->var_name[0])
				swaper(actual, next_node);
			else
				next_node = next_node->next;
		}
		actual = actual->next;
	}
}
