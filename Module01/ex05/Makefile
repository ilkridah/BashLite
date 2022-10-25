# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 04:02:46 by ilkridah          #+#    #+#              #
#    Updated: 2022/10/25 04:02:47 by ilkridah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Harl
SRC				= main.cpp Harl.cpp 
OBJ				= $(SRC:.cpp=.o)	

CC				= c++
CXXFLAGS		= -Wall -Wextra -Werror  -std=c++98 
RM				= rm -f

all:	$(NAME)

$(NAME):		$(OBJ) Harl.hpp
				$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
				$(RM) $(OBJ)  
fclean:			clean
				$(RM) $(NAME)

re:				fclean all