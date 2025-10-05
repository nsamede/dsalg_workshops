#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 5
#define CAPACITY_INCREMENT 3

typedef struct {
    void* data;
} QueueElement;

typedef struct {
    QueueElement *buffer;    // Where the data is stored.
    int           length;    // The number of items in the queue.
    size_t        capacity;  // The maximum number of items in the queue.
} Queue;

Queue create_queue() {
    return (Queue) {
        .buffer = NULL,
        .length = 0,
        .capacity = INITIAL_CAPACITY
    };
}

// Adds an element to the tail of the queue.
void enqueue(Queue *queue, void* data) {
    // If the queue is empty, we need to allocate the initial buffer
    if (queue->length == 0) {
        queue->buffer = (QueueElement*) malloc(sizeof(QueueElement) * queue->capacity);
        if (!queue->buffer) {
           printf("failed to allocate initial buffer\n"); 
           queue->buffer = NULL;
           return;
        }
    }

    QueueElement element = { .data = data };

    // If we are at max capacity, increase capacity and expand buffer
    if (queue->length == queue->capacity) {
        size_t old_size = sizeof(QueueElement) * queue->capacity;
        size_t new_size = old_size + (sizeof(QueueElement) * CAPACITY_INCREMENT);

        QueueElement *new_buffer = realloc(queue->buffer, new_size); 
        if (!new_buffer) {
            printf("failed to resize buffer\n");
            return;
        }

        free(queue->buffer);
        queue->capacity += CAPACITY_INCREMENT;
    }
    
    queue->buffer[queue->length] = element;
    queue->length++;
}

void dequeue(Queue *queue) {
    if (queue->length == 0) {
        return;
    }

    // Move elements after the head backwards, overwriting it.
    QueueElement *dest = queue->buffer;
    QueueElement *source = queue->buffer + 1;
    size_t bytes = sizeof(QueueElement) * (queue->length - 1);

    memmove(dest, source, bytes);
    queue->length--;
}

void* peek(Queue *queue) {
    if (queue->length == 0) {
        return NULL;
    }

    return queue->buffer[0].data;
}

int length(Queue *queue) {
    return queue->length;
}

void destroy_queue(Queue *queue) {
    // We can only free memory we malloc'd,
    // anything else is not our concern.
    free(queue->buffer);

    *queue = create_queue();
}

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
    printf("length: %d\n", queue.length);

    dequeue(&queue);
    dequeue(&queue);
    printf("head: %s\n", (char*) peek(&queue));
    printf("length: %d\n", queue.length);

    destroy_queue(&queue);

    return 0;
}
