NAME			= Phonebook
SRC				= main.cpp Contact.cpp Book.cpp
OBJ				= $(SRC:.cpp=.o)	

C++				= c++
CFLAGS			= -std=c++98 -pedantic -Wall -Wextra -Werror
RM				= rm -f

all:	$(NAME)

$(NAME):		$(OBJ) Contact.hpp book.hpp
				$(C++) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
				$(RM) $(OBJ)  
fclean:			clean
				$(RM) $(NAME)

re:				fclean all
