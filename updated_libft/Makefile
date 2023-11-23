NAME      	= libft.a

LIBFT_DIR	= libft
PRINTF_DIR	= ft_printf
GNL_DIR		= get_next_line

SRC_LIBFT	= $(wildcard $(LIBFT_DIR)/*.c)
SRC_PRINTF	= $(wildcard $(PRINTF_DIR)/*.c)
SRC_GNL		= $(wildcard $(GNL_DIR)/*.c)

OBJ_LIBFT	= $(addprefix $(LIBFT_DIR)/, $(notdir $(SRC_LIBFT:.c=.o)))
OBJ_PRINTF	= $(addprefix $(PRINTF_DIR)/, $(notdir $(SRC_PRINTF:.c=.o)))
OBJ_GNL		= $(addprefix $(GNL_DIR)/, $(notdir $(SRC_GNL:.c=.o)))

OBJ			= $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL)
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc

all: $(NAME)

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
