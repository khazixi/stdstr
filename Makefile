CC = clang
CFLAGS = -g -Wall -Wextra

main: stdstr.o main.o
	$(CC) stdstr.o main.o -o main

stdstr.o: stdstr.c stdstr.h
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -f stdstr.o main.o
