NAME		=	philo
SRC			=	init_forks.c init_philos.c input_handler.c main.c philosopher.c
OBJ			=	$(SRC:%.c=%.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=thread

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