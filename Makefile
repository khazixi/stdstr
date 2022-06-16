CC = clang
CFLAGS = -g -Wall -Wextra -Werror -pedantic

main.o: main.c
	$(CC) $(CFLAGS) main.c -o main

clean:
	$(RM) -f main
	$(RM) -rf *.dSYM
