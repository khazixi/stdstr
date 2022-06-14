CC = clang
CFLAGS = -g -Wall -Wextra

main: stdstr.o main.o
	$(CC) $^ -o main

stdstr.o: stdstr.c stdstr.h
	$(CC) $(CFLAGS) -c $< -o $@


main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@


test: strops.o test.c
	$(CC) $(CFLAGS) -c test.c -o test.o
	$(CC) $< test.o -o $@
	lldb ./test

clean:
	$(RM) -f *.o main
