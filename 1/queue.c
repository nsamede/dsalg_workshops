#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue create_queue() {
    return (Queue) {
        .buffer = NULL,
        .length = 0,
        .capacity = INITIAL_CAPACITY
    };
}

void enqueue(Queue *queue, void* data) {
    // If the queue is empty, we need to allocate the initial buffer.
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

        // If realloc() gave us a new buffer, we must free the old one.
        if (new_buffer != queue->buffer) {
            free(queue->buffer);
        }
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

unsigned int length(Queue *queue) {
    return queue->length;
}

void reverse_queue(Queue *queue) {
    unsigned int queue_length = length(queue);
    // Looping until queue_length / 2 prevents duplicate swaps.
    for (unsigned int i = 0; i < queue_length / 2; i++) {
        unsigned int remaining = queue_length - 1 - i;

        void *temp = queue->buffer[i].data;
        queue->buffer[i].data = queue->buffer[remaining].data;
        queue->buffer[remaining].data = temp;
    }
}

void destroy_queue(Queue *queue) {
    // We can only free memory we malloc'd,
    // anything else is not our concern.
    free(queue->buffer);

    *queue = create_queue();
}

