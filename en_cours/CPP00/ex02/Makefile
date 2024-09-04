# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 13:26:29 by afavre            #+#    #+#              #
#    Updated: 2023/10/11 13:26:32 by afavre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= bank_account
CC				= g++-11
FLAGS			= -Werror -Wextra -Wall -std=c++98 -pedantic

GREEN = \033[0;92m
YELLOW = \033[0;93m
ENDCOLOR = \033[0;39m

SRC	=	tests.cpp Account.cpp
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