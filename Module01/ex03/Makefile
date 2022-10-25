# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkridah <ilkridah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 04:01:43 by ilkridah          #+#    #+#              #
#    Updated: 2022/10/25 04:01:44 by ilkridah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Human
SRC				= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp 
OBJ				= $(SRC:.cpp=.o)	

CC				= c++
CXXFLAGS		= -Wall -Wextra -Werror  -std=c++98 
RM				= rm -f

all:	$(NAME)

$(NAME):		$(OBJ) HumanA.hpp HumanB.hpp Weapon.hpp
				$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
				$(RM) $(OBJ)  
fclean:			clean
				$(RM) $(NAME)

re:				fclean all