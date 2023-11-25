#include "../include/queue.h"

struct queue_type {
  Element obstaculos[QUEUE_MAX_SIZE];
  int armazenados;
};

void queue_init(Queue* queue)
{
  *queue = malloc(sizeof(struct queue_type));
  if (*queue != NULL) {
    (*queue)->armazenados = -1;
  } else {
    printf("Erro ao alocar fila!\n");
  }
}

bool queue_is_full(Queue queue)
{
  return queue->armazenados == QUEUE_MAX_SIZE - 1;
}

bool queue_is_empty(Queue queue)
{
  return queue->armazenados == -1;
}

bool queue_enqueue(Queue queue, Element new_element)
{
  bool feedback = false;

  if (!queue_is_full(queue)) {
    queue->armazenados++;
    queue->obstaculos[queue->armazenados] = new_element;
    feedback = true;
  }

  return feedback;
}

Element queue_dequeue(Queue queue)
{
  Element removed = NULL;

  removed = queue->obstaculos[0];

  for (int i = 0; i < queue->armazenados; i++) {
    queue->obstaculos[i] = queue->obstaculos[i + 1];
  }

  queue->armazenados -= 1;

  return removed;
}

bool queue_destroy(Queue* queue)
{
  Element trash_collector;
  bool feedback = false;


  while (!queue_is_empty(*queue)) {
    trash_collector = queue_dequeue(*queue);
    obstacle_destroy(&trash_collector);
  }

  free(*queue);
  
  feedback = true;


  return feedback;
}