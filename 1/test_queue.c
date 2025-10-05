#include "queue.h"

#include <stdio.h>

int main() {
    Queue queue = create_queue();

    int val1 = 10;
    int val2 = 20;
    char val3[] = "hello world!";
    int val4 = 40;
    int val5 = 50;
    int val6 = 60;

    enqueue(&queue, &val1);
    enqueue(&queue, &val2);
    enqueue(&queue, &val3);
    enqueue(&queue, &val4);
    enqueue(&queue, &val5);
    enqueue(&queue, &val6);
    printf("head: %d\n", *(int*) peek(&queue));
    printf("length: %d\n", length(&queue));

    dequeue(&queue);
    dequeue(&queue);
    printf("head: %s\n", (char*) peek(&queue));
    printf("length: %d\n", length(&queue));

    destroy_queue(&queue);

    return 0;
}
