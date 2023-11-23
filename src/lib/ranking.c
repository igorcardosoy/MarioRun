#include "../include/ranking.h"

struct type_ranking {
    FILE *file;
    char **names;
    int *scores;
    int size;
};

void ranking_init(Ranking *ranking);

void ranking_save(Ranking ranking);

void ranking_add(Ranking ranking, char* name, int score);

char* ranking_get(Ranking ranking, int index);

void ranking_destroy(Ranking *ranking);

