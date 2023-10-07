/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:32:11 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/08 15:32:48 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	error_print(char *line)
{
	ft_putstr_fd("shell: export: `", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	g_exit_status = 1;
	return (true);
}
