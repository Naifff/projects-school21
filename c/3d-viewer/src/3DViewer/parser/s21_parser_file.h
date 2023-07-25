#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define CORRUPT_FILE 2
#define FAIL 1
#define s21_IS_NUMERIC(ch) ((ch) <= '9' && (ch) >= '0')
#define s21_IS_DOT(ch) (ch == '.')
#define s21_IS_MINUS(ch) ((ch) == '-')

typedef struct data_t {
  long verticesAmount;
  long facetsAmount;
  double *vertices;
  int *facets;
  long countEdge;
} data_t;

int getVertice(int *i, char str[1024], char coordinate[64]);
int getFace(int *i, char str[1024], char face[64]);
int parsingFile(data_t *data, const char *fileName);
void setCountVerticesAndFacets(data_t *data, char *str, FILE *fp);
void setVertices(data_t *data, char *str, int *count_v, int *i_v);
void setFacets(data_t *data, char *str, int *count_v, int *i_f);
double findMaxCoord(double *vertices, int amountVertices, int coord);
double findMinCoord(double *vertices, int amountVertices, int coord);
void freeData(data_t *data);