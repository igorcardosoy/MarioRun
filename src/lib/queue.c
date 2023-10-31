#include "../include/queue.h"

struct queue_type {
    int not_implemented;
};

void queue_init(Queue* queue);

bool queue_is_full(Queue queue);

bool queue_is_empty(Queue queue);

bool queue_enqueue(Queue queue, Element new_element);

Element queue_dequeue(Queue queue);