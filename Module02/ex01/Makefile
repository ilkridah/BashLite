# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 06:07:06 by ilkridah          #+#    #+#              #
#    Updated: 2022/11/18 06:07:07 by ilkridah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fixed-point
SRC				= main.cpp Fixed.cpp 
OBJ				= $(SRC:.cpp=.o)	

CC				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 
RM				= rm -f

all:	$(NAME)

$(NAME):		$(OBJ) Fixed.hpp
				$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
				$(RM) $(OBJ)  
fclean:			clean
				$(RM) $(NAME)

re:				fclean all
