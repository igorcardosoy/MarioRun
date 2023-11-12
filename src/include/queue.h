#include "./utils.h"
#include "./obstacle.h"

/**
 * Define o tamanho máximo da fila.
*/
#define QUEUE_MAX_SIZE 10

/**
 * Define o tipo de dado que será manipulado pela fila.
*/
typedef Obstacle Element;

/**
 * Define que a fila (Queue) é um PONTEIRO para uma
 * struct queue. Independente da definição da struct
 * o TAD deve atender as especificações apontadas.
*/
typedef struct queue_type* Queue;


/**
 * Inicializa o queue
*/
void queue_init(Queue* queue);

/**
 * Retorna se a queue está cheia em função da 
 * constante QUEUE_MAX_SIZE.
*/
bool queue_is_full(Queue queue);

/**
 * Retorna se a queue está vazia ou não.
*/
bool queue_is_empty(Queue queue);

/**
 * Insere um novo elemento no final da fila.
*/
bool queue_enqueue(Queue queue, Element new_element);

/**
 * Remove o primeiro elemento da fila.
*/
Element queue_dequeue(Queue queue);

/**
 * Libera a memória alocada pela fila e por cada elemento.
*/
bool queue_destroy(Queue* queue);