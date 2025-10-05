# Worksheet 1: Stack, Queue

My solutions to the programming exercises from worksheet 1.
1. [x] Implement a Queue using an Array/List.  
2. [x] Implement a Stack using an Array/List.
3. [ ] Design an algorithm to reverse a Queue using Stacks and Queues.
4. [ ] (Advanced) Implement a Circular Queue using an Array or List.
5. [ ] Develop an algorithm to determine if the brackets in a string are valid, using
a Stack or a Queue.

## Building and Running

### Requirements
- GNU C Compiler[^1] 
- GNU Make [^2]
> [!TIP]
> If you'd like to use a different C compiler, edit the `CC` variable in the [Makefile](1/Makefile). \
> For example: `CC=clang`
[^1]: This code has been tested with GCC version 14.3.0, however older versions will likely work.
[^2]: This code has been tested with Make version 4.4.1, however older versions will likely work.

### Steps

```
cd dsalg_workshops/1
mkdir bin 			# Where Make will output binaries
make [target]		# Targets and their descriptions are listed below
./bin/[target]      # Run the desired binary
```
__Make Targets:__
- all - Builds all targets.
- test_stack - Builds test for the stack implementation (exercise 1).
- test_queue - Builds test for the queue implementation (exercise 2).
