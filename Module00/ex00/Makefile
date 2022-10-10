NAME			= megaphone
SRC				= megaphone.cpp 

C++				= c++
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

all:	$(NAME)

$(NAME):		$(SRC) 
				$(C++) $(CFLAGS) $(SRC) -o $(NAME)

clean:
				$(RM) $(NAME) 

fclean:			
				$(RM) $(NAME)

re:				fclean all
