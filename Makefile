CC=gcc
SRCS=$(wildcard, ./tests/*.c)
OBJS=$(pathsubst ./tests/%.c,./bin/%.o,$(SRCS))
CFLAGS=-g -O0

all: pre-build $(OBJS)
	$(CC) $(OBJS) -o ./bin/test

pre-build:
	mkdir -p ./bin

./bin/%.o: ./%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ./bin
