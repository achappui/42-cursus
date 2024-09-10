NAME			= test_interface
CC				= g++-11
FLAGS			= -Werror -Wextra -Wall -std=c++98 -pedantic

GREEN = \033[0;92m
YELLOW = \033[0;93m
ENDCOLOR = \033[0;39m

SRC	=	abstract_class/AMateria.cpp \
		concrete_class/Character.cpp \
		concrete_class/Cure.cpp \
		concrete_class/Ice.cpp \
		concrete_class/MateriaSource.cpp \
		main.cpp
OBJ =	$(SRC:.cpp=.o)

RM = rm -f

all:		$(NAME)


$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ)
			@echo "$(GREEN) Done ! $(ENDCOLOR)"

%.o: %.cpp
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(YELLOW) Cleaned ! $(ENDCOLOR)"

re:			fclean all

.PHONY:		all clean fclean re