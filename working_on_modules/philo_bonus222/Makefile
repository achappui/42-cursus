NAME		=	philo
SRC			=	counter_thread.c initializers.c main.c \
				philosopher_process.c dead_thread.c utils.c simulation.c
OBJ			=	$(SRC:%.c=%.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=thread

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