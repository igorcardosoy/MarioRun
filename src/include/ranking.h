#include "utils.h"

typedef struct type_ranking* Ranking;

// Função para inicializar o ranking, abrindo o arquivo e lendo o ranking.
void ranking_init(Ranking *ranking);

// Função para salvar o ranking no arquivo.
void ranking_save(Ranking ranking);

// Função para adicionar um score ao ranking, no ranking temp.
void ranking_add(Ranking ranking, char* name, int score);

// Função para recuperar uma informação do raking, baseado no index.
char* ranking_get(Ranking ranking, int index);

// Função para destruir o ranking, fechando o arquivo e liberando memoria.
void ranking_destroy(Ranking *ranking);

