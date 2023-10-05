CC = gcc
CFLAGS = -Wall

timer: timer.c
	$(CC) $(CFLAGS) -o timer timer.c

clean:
	rm -f timer