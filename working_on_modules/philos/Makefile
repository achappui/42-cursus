NAME		=	philo

SRC			=	initializer.c input_handler.c main.c

OBJ			=	$(SRC:%.c=%.o)

CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re