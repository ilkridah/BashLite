NAME			= Phonebook
SRC				= main.cpp Contact.cpp Phonebook.cpp
OBJ				= $(SRC:%.cpp=%.o)	

CC				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98	
RM				= rm -f

all:	$(NAME)

$(NAME):		$(OBJ) Contact.hpp Phonebook.hpp
				$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

# .cpp.o:
# 				$(CC) $(CPFLAGS) $(XXFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJ)  
fclean:			clean
				$(RM) $(NAME)

re:				fclean all
