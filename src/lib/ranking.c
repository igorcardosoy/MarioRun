#include "../include/ranking.h"

struct type_ranking {
  FILE* file;
  char** scores;
  int* score_points;
  int size;
};

void ranking_init(Ranking* ranking)
{
  *ranking = malloc(sizeof(struct type_ranking));

  (*ranking)->file = fopen("./src/assets/scores.txt", "r+");
  if ((*ranking)->file == NULL)
    printf("Erro ao abrir arquivo de ranking!\n");

  (*ranking)->size = 10;
  (*ranking)->score_points = malloc(sizeof(int) * (*ranking)->size);
  (*ranking)->scores = malloc(sizeof(char*) * (*ranking)->size);

  for (int i = 0; i < (*ranking)->size; i++) {
    (*ranking)->scores[i] = malloc(sizeof(char) * 20);
    fgets((*ranking)->scores[i], 20, (*ranking)->file);

    strtok((*ranking)->scores[i], "-");
    (*ranking)->score_points[i] = atoi(strtok(NULL, " "));

    printf("%s\n", ranking_get(*ranking, i));
  }
}

void ranking_save(Ranking ranking)
{
  rewind(ranking->file);
  char* buffer = malloc(sizeof(char) * 20);
  for (int i = 0; i < ranking->size; i++) {
    snprintf(buffer, 20, "%s- %d;\n", ranking->scores[i], ranking->score_points[i]);
    fputs(buffer, ranking->file);
  }
}

bool ranking_add(Ranking ranking, char* name, int score)
{
  bool is_greater = false;

  int i = 0;
  while (i < ranking->size && !is_greater) {
    if (score > ranking->score_points[i]) {
      for (int j = ranking->size - 1; j > i; j--) {
        ranking->score_points[j] = ranking->score_points[j - 1];
        strcpy(ranking->scores[j], ranking->scores[j - 1]);
      }
      ranking->score_points[i] = score;
      snprintf(ranking->scores[i], 20, "%s ", name);
      is_greater = true;
    }
    i++;
  }

  return is_greater;
}

bool ranking_is_greater(Ranking ranking, int score)
{
  bool is_greater = false;

  int i = 0;
  while (i < ranking->size && !is_greater) {
    if (score > ranking->score_points[i]) {
      is_greater = true;
    }
    i++;
  }

  return is_greater;
}

char* ranking_get(Ranking ranking, int index)
{
  char* score = malloc(sizeof(char) * 20);
  snprintf(score, 20, "%s- %d\n", ranking->scores[index], ranking->score_points[index]);
  return score;
}

int ranking_get_size(Ranking ranking)
{
  return ranking->size;
}

void ranking_destroy(Ranking* ranking)
{
  for (int i = 0; i < 10; i++) {
    free((*ranking)->scores[i]);
  }
  free((*ranking)->scores);
  fclose((*ranking)->file);
  free(*ranking);
}

