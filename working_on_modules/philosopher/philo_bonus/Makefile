NAME		=	philo_bonus
SRC			=	counter_thread_bonus.c initializers_bonus.c main_bonus.c \
				philosopher_process_bonus.c dead_thread_bonus.c utils_bonus.c simulation_bonus.c
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