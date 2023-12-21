NAME		=	push_swap
NAME_BONUS	=	checker

SRC			=	main.c input_handler.c operations.c \
				sorting_algo.c sorting_algo_utils.c radix_sort.c
SRC_BONUS	=	input_handler_bonus.c main_bonus.c \
				operations_bonus.c steps_file_bonus.c
OBJ			=	$(addprefix mendatory/, $(notdir $(SRC:%.c=%.o)))
OBJ_BONUS	=	$(addprefix bonus/, $(notdir $(SRC_BONUS:%.c=%.o)))
DEP			=	$(OBJ:%.o=%.d)
DEP_BONUS	=	$(OBJ_BONUS:%.o=%.d)

CFLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

all: $(NAME)

bonus: $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MP -MF $*.d

-include $(DEP) $(DEP_BONUS)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $^ libft/libft.a -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $^ libft/libft.a -o $(NAME_BONUS)

clean:
	make clean -C libft
	rm -f $(OBJ) $(OBJ_BONUS) $(DEP) $(DEP_BONUS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
