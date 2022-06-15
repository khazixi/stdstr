CC = clang
CFLAGS = -g -Wall -Wextra -pedantic

main: stdstr.o main.o
	$(CC) $^ -o main

stdstr.o: stdstr.c stdstr.h
	$(CC) $(CFLAGS) -c $< -o $@


main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -f *.o main
