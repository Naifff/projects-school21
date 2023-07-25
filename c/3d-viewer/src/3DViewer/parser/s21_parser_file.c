#include "s21_parser_file.h"

int getVertice(int *i, char str[1024], char coordinate[64]) {
  int error = OK;
  int j = 0;
  while (str[*i] != ' ' && str[*i] != '\n' && !error) {
    coordinate[j++] = str[(*i)++];
  }
  return error;
}

int getFace(int *i, char str[1024], char face[64]) {
  int error = OK;
  int faceIsReceived = 0;
  int j = 0;
  while (str[*i] != ' ' && str[*i] != '\n' && !error) {
    if (s21_IS_NUMERIC(str[*i]) || s21_IS_MINUS(str[*i])) {
      if (!faceIsReceived) face[j++] = str[*i];
    } else if (face[0] && str[*i] == '/') {
      faceIsReceived = 1;
    }
    (*i)++;
  }
  face[j] = '\0';
  return error;
}

void freeData(data_t *data) {
  if (data) {
    data->facetsAmount = 0;
    data->verticesAmount = 0;
    //    if (data->vertices) free(data->vertices);
    //    if (data->facets) free(data->facets);
    if (data->vertices) {
      free((data->vertices));
      data->vertices = NULL;
    }
    if (data->facets) {
      free((data->facets));
      data->facets = NULL;
    }
    data->countEdge = 0;
  }
}

int parsingFile(data_t *data, const char *fileName) {
  FILE *fp = fopen(fileName, "r");
  int error = OK;
  if (fp == NULL) {
    //    freeData(data);
    error = CORRUPT_FILE;
  } else {
    char str[1024] = {'\0'};
    setCountVerticesAndFacets(data, str, fp);
    data->vertices = calloc(data->verticesAmount * 3, sizeof(double));
    data->facets = calloc(data->facetsAmount * 2, sizeof(int));
    if (data->vertices && data->facets) {
      int count_v = 0;
      int i_v = 0;
      int i_f = 0;
      fseek(fp, 0, SEEK_SET);
      while (fgets(str, 1024, fp) != NULL) {
        if (str[0] == 'v' && str[1] == ' ') {
          setVertices(data, str, &count_v, &i_v);
        }
        if (str[0] == 'f' && str[1] == ' ') {
          setFacets(data, str, &count_v, &i_f);
        }
      }
      data->countEdge = data->facetsAmount / 2;
    } else {
      error = CORRUPT_FILE;
      freeData(data);
    }
    fclose(fp);
  }
  return error;
}

void setCountVerticesAndFacets(data_t *data, char *str, FILE *fp) {
  while (fgets(str, 1024, fp) != NULL) {
    if (str[0] == 'v' && str[1] == ' ') {
      data->verticesAmount++;
    }
    if (str[0] == 'f' && str[1] == ' ') {
      for (int i = 1; str[i] != '\n'; i++) {
        if (str[i - 1] == ' ' &&
            (s21_IS_NUMERIC(str[i]) || s21_IS_MINUS(str[i])))
          data->facetsAmount++;
      }
    }
  }
}

void setVertices(data_t *data, char *str, int *count_v, int *i_v) {
  *count_v += 1;
  for (int i = 2, xyz = 0; str[i] != '\0' && xyz < 3; i++) {
    if (s21_IS_NUMERIC(str[i]) || s21_IS_MINUS(str[i])) {
      char coordinate[64] = {'\0'};
      getVertice(&i, str, coordinate);
      (data->vertices)[*i_v] = atof(coordinate);
      *i_v += 1;
      xyz++;
    }
  }
}

void setFacets(data_t *data, char *str, int *count_v, int *i_f) {
  int firstItem = -1;
  for (int i = 2; str[i] != '\0'; i++) {
    if (s21_IS_NUMERIC(str[i]) || s21_IS_MINUS(str[i])) {
      char face[64] = {'\0'};
      getFace(&i, str, face);
      (data->facets)[*i_f] = atoi(face) - 1;
      if ((data->facets)[*i_f] < 0) {
        (data->facets)[*i_f] += (*count_v + 1);
      }
      if (firstItem >= 0) {
        (data->facets)[*i_f + 1] = (data->facets)[*i_f];
        *i_f += 1;
      } else {
        firstItem = (data->facets)[*i_f];
      }
      *i_f += 1;
    }
  }
  (data->facets)[*i_f] = firstItem;
  *i_f += 1;
}
