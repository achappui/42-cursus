SRC		=	main.c input_handler.c operations.c
OBJ		=	$(SRC:%.c=%.o)
NAME	=	push_swap
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc
HEADERS	=	push_swap.h

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MP -MF $*.d

-include $(SRC:%.c=%.d)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $^ libft/libft.a -o $@

clean:
	make clean -C libft
	rm -f $(OBJ) $(OBJ:%.o=%.d)

fclean:
	make fclean -C libft
	rm -f $(OBJ) $(OBJ:%.o=%.d) $(NAME)

re: fclean all

.PHONY: all clean fclean re