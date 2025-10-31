NAME	= PmergeMe
CC		= c++
FLAGS	= -Werror -Wextra -Wall -std=c++98 -pedantic

SRC		= main.cpp PmergeMe.cpp argvParsing.cpp
OBJ		= main.o PmergeMe.o argvParsing.o

RM		= rm -f

all:		$(NAME)


$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ)
			@echo "Done !"

%.o: %.cpp
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)
			@echo "Cleaned !"

re:			fclean all

.PHONY:		all clean fclean re
