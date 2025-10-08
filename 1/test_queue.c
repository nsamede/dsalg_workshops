#include "queue.h"

#include <stdio.h>

int main() {
    Queue queue = create_queue();

    int values[6] = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 6; i++) {
        enqueue(&queue, &values[i]);
    }

    printf("after enqueue:\n");
    printf("\thead: %d\n", *(int*) peek(&queue));
    printf("\tlength: %d\n", length(&queue));

    printf("\tvalues: { ");
    for (int i = 0; i < 6; i++) {
        printf("%d, ", *(int*) queue.buffer[i].data);
    }
    printf("}\n");

    printf("after dequeue (twice):\n");
    dequeue(&queue);
    dequeue(&queue);
    printf("\thead: %d\n", *(int*) peek(&queue));
    printf("\tlength: %d\n", length(&queue));

    printf("\tvalues: { ");
    for (int i = 0; i < length(&queue); i++) {
        printf("%d, ", *(int*) queue.buffer[i].data);
    }
    printf("}\n");

    reverse_queue(&queue);
    printf("after reverse:\n");
    printf("\thead: %d\n", *(int*) peek(&queue));
    printf("\tlength: %d\n", length(&queue));

    printf("\tvalues: { ");
    for (int i = 0; i < length(&queue); i++) {
        printf("%d, ", *(int*) queue.buffer[i].data);
    }
    printf("}\n");

    destroy_queue(&queue);

    return 0;
}
