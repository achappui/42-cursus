CLIENT		=	client
SERVER		=	server
LIBFT		=	libft

SRC_CLIENT	=	srcs/client.c
SRC_SERVER	=	srcs/server.c

OBJ_CLIENT	=	$(SRC_CLIENT:%.c=%.o)
OBJ_SERVER	=	$(SRC_SERVER:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(OBJ_SERVER)
	make -C libs/libft
	$(CC) $(CFLAGS) $^ libs/libft/libft.a -o $@

$(CLIENT): $(OBJ_CLIENT)
	make -C libs/libft
	$(CC) $(CFLAGS) $^ libs/libft/libft.a -o $@

clean:
	make clean -C libs/libft
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	make fclean -C libs/libft
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re