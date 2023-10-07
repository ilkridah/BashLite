/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:54:45 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/16 17:38:21 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <errno.h>
# include <string.h>

typedef struct s_env
{
	char			*line;
	char			*var_name;
	char			*var_value;
	struct s_env	*prev;
	struct s_env	*next;
}t_env;

typedef struct s_token
{
	char			*str;
	int				type;
	int				state;
	struct s_token	*prev;
	struct s_token	*next;
}t_token;

typedef struct s_infos
{
	char	*cmd;
	char	**flags;
	char	**arg_enf;
	bool	builtin;
	bool	redir_in;
	bool	redir_out;
	int		fd_in;
	int		fd_out;
	int		error;
	char	*err_msg;
}t_infos;

typedef struct s_exec
{
	char	*path;
	char	**env_array;
	char	**cmd_and_flags;
}t_exec;

typedef struct s_cmd
{
	bool			is_pip;
	t_infos			info;
	struct s_cmd	*left;
	struct s_cmd	*right;
}t_cmd;

typedef struct s_data
{
	char	**envp;
	t_env	*env_copy;
	t_env	*env_export;
	char	*line;
	t_token	*token;
	t_cmd	*cmd;
	pid_t	pid;
}t_data;

enum e_type
{
	BLANK = 1,
	WORD,
	VAR,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND,
	END
};

#endif
