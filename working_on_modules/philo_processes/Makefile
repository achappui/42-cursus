NAME		=	philo
SRC			=	death_counter.c end_checker.c initializers_utils.c \
				initializers.c main.c philosopher.c
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