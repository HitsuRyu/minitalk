CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -L./libft -lft
LIBFT = libft.a

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	make -C libft

$(SERVER): server.o
	$(CC) server.o $(LIB) -o $@

$(CLIENT): client.o
	$(CC) client.o $(LIB) -o $@

bonus : $(LIBFT) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): client_bonus.o
	$(CC) client_bonus.o $(LIB) -o $@

$(SERVER_BONUS): server_bonus.o
	$(CC) server_bonus.o $(LIB) -o $@

%.o : %.c
	$(CC) $(FLAGS) $< -c

clean :
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C libft
	rm -f $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all