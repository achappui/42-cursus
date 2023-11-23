NAME      	=	libft.a

LIBFT_DIR	= 	libft
PRINTF_DIR	= 	ft_printf
GNL_DIR		= 	get_next_line

SRC_LIBFT	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
				ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC_PRINTF	= 	ft_printf/ft_printf.c ft_printf/ft_options.c \
				ft_printf/ft_print_integers.c ft_printf/ft_print_letters.c

SRC_GNL		=	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ_LIBFT	=	$(addprefix $(LIBFT_DIR)/, $(notdir $(SRC_LIBFT:%.c=%.o)))
OBJ_PRINTF	= 	$(addprefix $(PRINTF_DIR)/, $(notdir $(SRC_PRINTF:%.c=%.o)))
OBJ_GNL		=	$(addprefix $(GNL_DIR)/, $(notdir $(SRC_GNL:%.c=%.o)))

OBJ			=	$(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL)
CFLAGS		=	-Wall -Wextra -Werror
CC			=	gcc

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
