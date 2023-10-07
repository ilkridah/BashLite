/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:54:32 by ikharbac          #+#    #+#             */
/*   Updated: 2022/09/16 17:50:57 by ilkridah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "struct.h"

extern int	g_exit_status;

int		ft_init(t_data *data, char **envp);
t_env	*ft_lstnew_node(char *line, char *name, char *value);
void	ft_lstadd_back(t_env **lst, t_env *new);
int		ft_tokenize(t_data *data, char *line);
char	*find_name(char *line);
char	*find_val(char *line);
int		check_status(int status, char *line, int i);
int		stock_word_and_sep(int *i, char *line, int start, t_data *data);
void	free_token(t_data *data);
void	ft_free_struct(t_data *data);
t_token	*ft_new_token(char *str, int type, int state);
void	ft_add_back_token(t_token **lst, t_token *new);
int		collect_information(t_token **list);
int		expander(t_data *data, t_token **token);
char	*collect_value(t_data *data, char *var);
int		expander(t_data *data, t_token **token);
char	*var_val(char *str, t_data *list);
void	copy_value(char *new, char *value, int *j);
int		fill_var(t_token **list, char *value);
int		check_next(char s);
int		check_dollar_quotes(char *str, int i);
int		check_cases(char s);
int		count_len(char *str);
char	*join_var(char *str);
int		check_next(char s);
int		quotes_proc(t_data *data);
int		check_quotes(char *str);
int		count_len_quotes(char *str, int count, int i);
int		if_default(t_token **token, int i);
void	change_to_quote(t_token **token, int *i);
int		change_to_default(t_token **token, int *i);
void	creating_commands(t_data *cmds, t_token *tokens);
t_cmd	*ft_lstnew_cmd(int val);
void	ft_lstadd_back_cmd(t_cmd **list, t_cmd *new);
t_cmd	*last_cmd(t_cmd *cmd);
void	add_cmd(t_cmd *cmd, char *str);
int		creat_flag(t_token **tokens, t_cmd *cmd);
char	**copy_old_to_new(int len, char **new, t_cmd *cmd, t_token **token);
int		join_flags(t_token **tokens, t_cmd *cmd);
int		creat_flags(t_token **token, t_cmd *cmd);
void	words_parsing(t_cmd **cmd, t_token **list);
void	print_error(t_cmd *cmd, char *file);
void	parsing_redir_in(t_cmd **cmd, t_token **tokens);
void	parsing_redir_out(t_cmd **cmd, t_token **tokens);
void	parsing_append(t_cmd **cmd, t_token **tokens);
void	parsing_pipe(t_cmd **cmd, t_token **tokens);
int		len_flags(t_token *tmp);
int		add_echo_flag(t_token **tokens, t_cmd *cmd);
char	*get_line(char *line, char *delimiter, char *str);
void	heredoc_child(int *pipe_fd, t_token **list, t_data *data);
void	heredoc_parent(t_data *data, int *pipe_fd);
void	export_var(t_env **env, char *line, char *var, char *val);
void	free_var_val(char *var, char *val);
void	replace_var(t_env *tmp, char *line, char *var, char *val);
void	add_var_to_env(t_data *data, char *line, char *var, char *value);
int		export(t_data *data, t_cmd *cmd, t_env **env);
void	export_no_flag(t_cmd *cmd, t_env **env);
int		if_valid(char *line);
int		if_already_exported(t_env *env, char *var);
void	ft_add_back_node(t_env **env, t_env *new_node);
t_env	*ft_new_node(char *line, char *name, char *value);
int		error_print(char *line);
int		envp_checker(char **envp);
void	pwd(t_cmd *cmd, t_env *env);
int		env(t_cmd *cmd, t_env **env);
int		cd(t_cmd *cmd, t_env **env);
int		unset(t_data *data, t_cmd *cmd);
int		ft_exit(t_cmd *cmd);
void	echo(t_cmd *cmd);
void	close_fd_builtin(t_cmd *cmd);
int		builtin_execution(t_data *data, t_cmd *cmd);
void	close_fd_builtin(t_cmd *cmd);
void	child(t_data *data, t_cmd *cmd, int *tube);
t_exec	*get_execve_infos(t_data *data, t_cmd *cmd);
char	*get_cmd_path(char **env, char *cmd);
char	**env_copy(t_env *env);
int		get_start(char **env);
char	*join_path(char *s1, char *s2);
void	free_tab(char **path);
int		env_len(t_env *env);
char	**creat_cmd(t_cmd *cmd);
void	parent(t_cmd *cmd, int *tube);
void	wait_and_close(t_data *data, t_cmd *cmd);
int		execution(t_data *data);
void	builtin_with_pipe(t_cmd *cmd, t_data *data, int *tube);
void	change_in_out(t_cmd *cmd, int *tube);
void	aka_signal(int action);
void	export_sort(t_env *env);
#endif