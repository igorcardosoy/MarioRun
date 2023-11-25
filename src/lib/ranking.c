#include "../include/ranking.h"

struct type_ranking {
  FILE* file;
  char** names;
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
  (*ranking)->names = malloc(sizeof(char*) * (*ranking)->size);

  for (int i = 0; i < (*ranking)->size; i++) {
    (*ranking)->names[i] = malloc(sizeof(char) * 20);
    fgets((*ranking)->names[i], 20, (*ranking)->file);

    strtok((*ranking)->names[i], "-");
    (*ranking)->score_points[i] = atoi(strtok(NULL, " "));

    printf("%s\n", ranking_get(*ranking, i));
  }
}

void ranking_save(Ranking ranking)
{
  rewind(ranking->file);
  char* buffer = malloc(sizeof(char) * 20);
  for (int i = 0; i < ranking->size; i++) {
    snprintf(buffer, 20, "%s- %d;\n", ranking->names[i], ranking->score_points[i]);
    fputs(buffer, ranking->file);
  }
}

bool ranking_add(Ranking ranking, char* name, int score)
{
  bool is_greater = false;
  bool is_on_ranking = false;
  int i = 0;

  snprintf(name, 20, "%s ", name);

  while (i < ranking->size && !is_on_ranking) {

    printf("%s.\n", ranking->names[i]);
    printf("%s.\n", name);

    if (strcmp(name, ranking->names[i]) == 0) {
      is_on_ranking = true;
    }
    i++;
  }

  if (!is_on_ranking) {
    i = 0;
    while (i < ranking->size && !is_greater) {
      if (score > ranking->score_points[i]) {
        for (int j = ranking->size - 1; j > i; j--) {
          ranking->score_points[j] = ranking->score_points[j - 1];
          strcpy(ranking->names[j], ranking->names[j - 1]);
        }
        ranking->score_points[i] = score;
        snprintf(ranking->names[i], 20, "%s", name);
        is_greater = true;
      }
      i++;
    }
  } else {
    i--;
    if (score > ranking->score_points[i]) {
      ranking->score_points[i] = score;
      is_greater = true;
    }
  }

  // Sorts the ranking
  for (int i = 0; i < ranking->size; i++) {
    for (int j = i + 1; j < ranking->size; j++) {
      if (ranking->score_points[i] < ranking->score_points[j]) {
        int temp = ranking->score_points[i];
        ranking->score_points[i] = ranking->score_points[j];
        ranking->score_points[j] = temp;

        char* temp_name = malloc(sizeof(char) * 20);
        strcpy(temp_name, ranking->names[i]);
        strcpy(ranking->names[i], ranking->names[j]);
        strcpy(ranking->names[j], temp_name);
      }
    }
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
  char* score = malloc(sizeof(char) * 25);
  snprintf(score, 25, "%s- %d\n", ranking->names[index], ranking->score_points[index]);
  return score;
}

int ranking_get_size(Ranking ranking)
{
  return ranking->size;
}

void ranking_destroy(Ranking* ranking)
{
  for (int i = 0; i < 10; i++) {
    free((*ranking)->names[i]);
  }
  free((*ranking)->names);
  fclose((*ranking)->file);
  free(*ranking);
}

