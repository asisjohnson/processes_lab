CC = gcc
CFLAGS = -Wall -std=c99

all: process_lab

process_lab: processes_lab.c
	$(CC) $(CFLAGS) -o process_lab processes_lab.c

clean:
	rm -f process_lab