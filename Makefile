CLIENT = client
SERVER = server
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

%.o : %.c
	$(CC) $(FLAGS) $< -c

clean :
	make clean -C libft
	rm -f *.o

fclean: clean
	make fclean -C libft
	rm -f $(SERVER) $(CLIENT)

re: fclean all