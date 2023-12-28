CLIENT		=	client
SERVER		=	server
LIBFT		=	libft

SRC_CLIENT	=	srcs/client_mendatory/main.c
SRC_SERVER	=	srcs/server_mendatory/main.c

OBJ_CLIENT	=	$(SRC_CLIENT:%.c=%.o)
OBJ_SERVER	=	$(SRC_SERVER:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(libft) $(SERVER) $(CLIENT)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

$(libft):
	make -C libs/libft

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re