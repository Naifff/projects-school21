#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_

#include <stdio.h>
#include <stdlib.h>
FILE* log_init();
void logcat(FILE *log, char *new, char *mess, char *path);
void log_close(FILE *log);

#endif  // SRC_LOGGER_H_
