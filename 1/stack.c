#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5
#define CAPACITY_INCREMENT 3


Stack create_stack() {
    return (Stack) {
        .buffer = NULL,
        .length = 0,
        .capacity = INITIAL_CAPACITY,
    };
}

void push(Stack *stack, void *data) {
    // If the stack is empty, we need to initialise it.
    if (stack->length == 0) {
        stack->buffer = malloc(sizeof(StackElement) * INITIAL_CAPACITY);
        if (!stack->buffer) {
            printf("failed to allocate initial buffer");
            stack->buffer = NULL;
            return;
        }
    }
    
    StackElement element = { .data = data };

    // If we are at max capacity, increase capacity and expand buffer.
    if (stack->length == stack->capacity) {
        size_t old_size = sizeof(StackElement) * stack->capacity;
        size_t new_size = old_size + (sizeof(StackElement) * CAPACITY_INCREMENT);

        StackElement *new_buffer = realloc(stack->buffer, new_size);
        if (!new_buffer) {
            printf("failed to resize buffer\n");
            return;
        }

        stack->buffer = new_buffer;
    }    

    stack->buffer[stack->length] = element;
    stack->length++;
}

void pop(Stack *stack) {
    if (stack->length == 0) {
        return;
    }
    
    // No need to realloc here, we can reuse the memory
    // for future elements.
    stack->length--;
}

void *peek(Stack *stack) {
    return stack->buffer[stack->length - 1].data;
}

int length(Stack *stack) {
    return stack->length;
}

void destroy_stack(Stack *stack) {
    // We can only free what *we* allocated,
    // memory inside StackElements is not our responsibilty.
    free(stack->buffer);

    *stack = create_stack();
}
