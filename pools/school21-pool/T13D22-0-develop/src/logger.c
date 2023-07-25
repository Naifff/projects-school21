#include "logger.h"
#include <time.h>

FILE* log_init() {
    FILE *log;
        if ((log = fopen("logs.txt", "a")) == NULL) {
            printf("n/a");
}
return log;
}

void logcat(FILE *log, char *new, char *mess, char *path) {
    fputs(new, log);
    int s, m, h;
    time_t timer;
    time(&timer);
    struct tm *time = localtime(&timer);
    s = time->tm_sec;
    h = time->tm_hour;
    m = time->tm_min;
    fprintf(log, "%02d:%02d:%02d ", h, m, s);
    fprintf(log, "File \"%s\" was %s\n", path, mess);
}

void log_close(FILE *log) {
    fclose(log);
}
