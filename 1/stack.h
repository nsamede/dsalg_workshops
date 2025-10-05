#ifndef STACK
#define STACK

#include <stdlib.h>

/*
    The internal type responsible for holding each element's data.
    This type is not intended to be used directly.
*/
typedef struct {
    void *data;
} StackElement;

typedef struct {
    StackElement *buffer;    // Where the data is stored.
    unsigned int  length;    // The number of items in the stack.
    unsigned int  capacity;  // The maximum number of items in the stack.
} Stack;

/*
    Initialises the stack, but does NOT allocate the inital buffer.
    The initial buffer is allocated when the first element is pushed.
    This is so memory is only allocated when it is going to be used.
*/
Stack create_stack();

// Adds an element to the top of the stack.
void push(Stack *stack, void *data);

// Removes the element at the top of the stack.
void pop(Stack *stack);

// Returns the element at the top of the stack.
void *peek(Stack *stack);

// Returns the number of elements in the stack.
int length(Stack *stack);

// De-allocates the stack's internal buffer and re-initialises the stack.
void destroy_stack(Stack *stack);

#endif // STACK
