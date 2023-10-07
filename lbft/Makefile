# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 15:13:47 by ilkridah          #+#    #+#              #
#    Updated: 2021/11/27 15:13:54 by ilkridah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

SRCS    =  ft_isdigit.c ft_memset.c ft_isprint.c ft_memcpy.c           \
		   ft_memchr.c ft_strchr.c ft_strdup.c ft_memmove.c    \
		   ft_strncmp.c ft_atoi.c ft_memcmp.c ft_strlcat.c     \
		   ft_calloc.c ft_strlcpy.c  ft_strrchr.c ft_bzero.c   \
		   ft_strlen.c ft_isalpha.c ft_isalnum.c ft_isascii.c  \
		   ft_toupper.c ft_tolower.c ft_strnstr.c ft_substr.c  \
		   ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c    \
		   ft_striteri.c ft_putstr_fd.c ft_putchar_fd.c        \
		   ft_putnbr_fd.c ft_putendl_fd.c ft_split.c 	       \
		   
HEADER	=	libft.h

OBJS    =    ${SRCS:.c=.o}

CC =    gcc

FLAGS =    -Wall -Wextra -Werror

all	:	$(NAME)

%.o :	%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):    $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:    clean
	rm -rf $(NAME)

re: fclean all
