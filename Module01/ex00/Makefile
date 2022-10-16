NAME			= zombie
SRC				= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
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
