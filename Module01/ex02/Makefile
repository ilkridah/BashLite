NAME			= main
SRC				= main.cpp 

CC				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98	
RM				= rm -f

all:	$(NAME)

$(NAME):		$(SRC) 
				$(CC) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
				$(RM) $(NAME) 

fclean:			
				$(RM) $(NAME)

re:				fclean all
