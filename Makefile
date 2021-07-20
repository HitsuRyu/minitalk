all:
	gcc server.c -o server.out -L. -lft
	gcc client.c -o client.out -L. -lft

clean:
	rm -f server client

