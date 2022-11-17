NAME			= a.out
SRC				= main.cpp 
OBJ				= $(SRC:.cpp=.o)	

CC				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++11 
RM				= rm -f

all:	$(NAME)

$(NAME):		$(OBJ) 
				$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
clean:
				$(RM) $(OBJ)  
fclean:			clean
				$(RM) $(NAME)

re:				fclean all
