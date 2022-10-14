NAME			= Phonebook
SRC				= main.cpp Contact.cpp Phonebook.cpp
OBJ				= $(SRC:.cpp=.o)	

C++				= c++
CFLAGS			=  -Wall -Wextra -Werror -std=c++98
RM				= rm -f

all:	$(NAME)

$(NAME):		$(OBJ) Contact.hpp Phonebook.hpp
				$(C++) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
				$(RM) $(OBJ)  
fclean:			clean
				$(RM) $(NAME)

re:				fclean all
