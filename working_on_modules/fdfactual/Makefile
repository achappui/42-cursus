NAME	=	fdf

SRC		=	display_map_1.c display_map_2.c initializers.c \
			keyboard_actions_1.c keyboard_actions_2.c keyboard_actions_3.c \
			main.c parsing_1.c parsing_2.c parsing_3.c utils.c nocolor_map.c display_map_3.c
OBJ		=	$(SRC:%.c=%.o)

CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

all: $(NAME)

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C minilibx
	make -C libft
	$(CC) $(CFLAGS) -L minilibx -lmlx -L libft -lft -lm $^ -o $@ -framework OpenGL -framework AppKit

clean:
	make clean -C minilibx
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
