# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 04:01:16 by ilkridah          #+#    #+#              #
#    Updated: 2022/10/25 04:01:17 by ilkridah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= main
SRC				= main.cpp 

CC				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98	
RM				= rm -f

all:	$(NAME)

$(NAME):		$(SRC) 
				$(CC) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
				$(RM) $(NAME) 

fclean:			
				$(RM) $(NAME)

re:				fclean all
