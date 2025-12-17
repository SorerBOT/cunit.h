CC=gcc
SRCS:=$(wildcard tests/*.c)
OBJS:=$(patsubst tests/%.c,bin/%.o,$(SRCS))
CFLAGS= -g -O0

all: pre-build $(OBJS)
	$(CC) $(OBJS) -o ./bin/test

pre-build:
	mkdir -p ./bin

bin/%.o: tests/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ./bin
