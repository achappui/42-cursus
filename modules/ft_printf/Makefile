NAME	=	libftprintf.a
SRC		=	ft_printf.c ft_options.c ft_print_integers.c ft_print_letters.c
OBJ		=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a libftprintf.a
	ar rcs libftprintf.a $^

bonus: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re