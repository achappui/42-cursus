NAME	=	fdf

SRC		=	src/main.c src/input_handler_1.c src/input_handler_2.c src/input_handler_3.c
OBJ		=	$(SRC:%.c=%.o)
DEP		=	$(OBJ:%.o=%.d)

CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MP -MF $*.d

$(NAME): $(OBJ)
	make -C libs/libft
	$(CC) $(CFLAGS) $^ libs/libft/libft.a -o $@

clean:
	make clean -C libs/libft
	rm -f $(OBJ) $(DEP)

fclean: clean
	make fclean -C libs/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
