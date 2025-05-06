CC = gcc
CFLAGS = -Wall -Wextra -pedantic -Wno-parentheses -Wno-pedantic

MAIN_SRCS = int_functions.c DynamicArray.c str_functions.c main.c
TARGET = main

TEST_SRCS = int_functions.c DynamicArray.c str_functions.c tests.c
TEST_TARGET = tests

$(TARGET): $(MAIN_SRCS)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_SRCS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $^
	./$(TEST_TARGET)

.PHONY: clean test

clean:
	rm -f $(TARGET) $(TEST_TARGET)