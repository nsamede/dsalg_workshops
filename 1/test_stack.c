#include "stack.h"

#include <stdio.h>

int main() {
    Stack stack = create_stack();

    int val1 = 100;
    int val2 = 200;
    int val3 = 300;
    int val4 = 400;
    char val5[] = "hello world!";
    int val6 = 500;

    push(&stack, &val1);
    push(&stack, &val2);
    push(&stack, &val3);
    push(&stack, &val4);
    push(&stack, &val5);
    push(&stack, &val6);
    printf("top: %d\n", *(int*) peek(&stack));
    printf("length: %d\n", stack.length);    

    pop(&stack);
    pop(&stack);
    printf("top: %d\n", *(int*) peek(&stack));
    printf("length: %d\n", stack.length);    

    destroy_stack(&stack);

    return 0;
}
