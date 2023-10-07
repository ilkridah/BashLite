# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 19:53:01 by ikharbac          #+#    #+#              #
#    Updated: 2022/09/17 10:42:11 by ilkridah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= minishell

SRCS_DIR = $(addprefix srcs/, $(SRCS)) $(addprefix utils/, $(utils))
SRCS			=  main.c init.c tokenizer.c  tokenizer_utils.c allocate_tokenze.c
utils = env_utils.c free.c token_information.c expander.c expander_utils.c expander_utils1.c quotes_proc.c quotes_utils.c \
	 cmds.c add_cmds.c parse_word.c out_in.c parse_pipe.c parsing_heredoc.c export1.c export2.c pwd.c error.c \
	 env.c cd.c unset.c exit.c echo.c builtin.c child.c exec_info.c get_info2.c parent.c wait.c execution.c signals.c export_sort.c
CC				= cc
CFLAGS			= -Wextra -Wall -Werror
NFLAGS			= -L /Users/ikharbac/goinfre/.brew/opt/readline/lib 
PFALGS			= -I /Users/ikharbac/goinfre/.brew/opt/readline/include
RM				= rm -f

OBJ = $(SRCS_DIR:%.c=%.o)

all:		 $(NAME)

$(NAME):  $(OBJ) ./incl/minishell.h ./incl/struct.h
		make -C ./libft
		$(CC)  -lreadline $(NFLAGS) $(PFLAGS) $(OBJ) ./libft/libft.a -o $(NAME)
clean:
	rm -rf $(OBJ) $(OBJB)
	make clean -C ./libft
fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME) $(NAMEB)

re: fclean all
	make re -C ./libft
