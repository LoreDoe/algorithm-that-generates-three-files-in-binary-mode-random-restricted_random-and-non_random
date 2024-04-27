CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: file_generator

file_generator: file_generator.c
    $(CC) $(CFLAGS) file_generator.c -o file_generator

clean:
    rm -f file_generator *.bin
