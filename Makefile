CC = gcc
CFLAGS = -Wall -Wextra -pedantic -Wno-parentheses

SRCS = int_functions.c DynamicArray.c str_functions.c tests.c main.c
TARGET = main

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean