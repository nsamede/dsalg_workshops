all: test_stack test_queue

test_stack: test_stack.c stack.c
	cc -o test_stack test_stack.c stack.c

test_queue: test_queue.c queue.c
	cc -o test_queue test_queue.c queue.c

clean:
	rm test_stack test_queue
