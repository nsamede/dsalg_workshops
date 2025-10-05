#ifndef QUEUE
#define QUEUE

#include <stdlib.h>

#define INITIAL_CAPACITY 5
#define CAPACITY_INCREMENT 3

/*
    The internal type responsible for holding each element's data.
    This type is not intended to be used directly.
*/
typedef struct {
    void* data;
} QueueElement;

typedef struct {
    QueueElement *buffer;    // Where the data is stored.
    unsigned int  length;    // The number of items in the queue.
    unsigned int  capacity;  // The maximum number of items in the queue.
} Queue;

/*
    Initialises the queue, but does NOT allocate the inital buffer.
    The initial buffer is allocated when the first element is enqueue'd.
    This is so memory is only allocated when it is going to be used.
*/
Queue create_queue();

// Adds an element to the tail of the queue.
void enqueue(Queue *queue, void* data);

// Removes an element from the head of the queue.
void dequeue(Queue *queue);

// Returns the element at the head of the queue.
void* peek(Queue *queue);

// Returns the length of the queue.
int length(Queue *queue);

// De-allocates the queue's internal buffer and re-initialises the queue.
void destroy_queue(Queue *queue);

#endif // QUEUE
