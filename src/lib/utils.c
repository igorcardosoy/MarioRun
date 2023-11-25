#include "../include/utils.h"

int string_size(char* string)
{
  int size = 0;
  while (string[size] != '\n') {
    size++;
  }
  return size;
}