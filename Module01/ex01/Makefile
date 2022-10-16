NAME			= Horde
SRC				= main.cpp Zombie.cpp zombieHorde.cpp 
OBJ				= $(SRC:.cpp=.o)	

C++				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98 
RM				= rm -f

all:	$(NAME)

$(NAME):		$(OBJ) Zombie.hpp
				$(C++) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
				$(RM) $(OBJ)  
fclean:			clean
				$(RM) $(NAME)

re:				fclean all