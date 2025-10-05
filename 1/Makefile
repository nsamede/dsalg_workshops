CC=gcc

all: test_stack test_queue

test_stack: test_stack.c stack.c
	$(CC) -o bin/test_stack test_stack.c stack.c

test_queue: test_queue.c queue.c
	$(CC) -o bin/test_queue test_queue.c queue.c

clean:
	rm -rf bin
