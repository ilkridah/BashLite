NAME			= Human
SRC				= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CC				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98	
RM				= rm -f

all:	$(NAME)

$(NAME):		$(SRC) Weapon.hpp HumanA.hpp HumanB.hpp
				$(CC) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
				$(RM) $(NAME) 

fclean:			
				$(RM) $(NAME)

re:				fclean all
