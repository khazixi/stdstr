CC = clang
CFLAGS = -g -Wall -Wextra

main: stdstr.o main.o strops.o
	$(CC) $^ -o main

stdstr.o: stdstr.c stdstr.h
	$(CC) $(CFLAGS) -c $< -o $@

strops.o: strops.c strops.h
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -f *.o main
