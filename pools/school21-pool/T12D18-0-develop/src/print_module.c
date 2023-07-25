#include <stdio.h>
#include <time.h>
#include "print_module.h"

char print_char(char ch) {
    return putchar(ch);
}

void print_log(char(*print) (char), char* message) {
    int s, m, h;
    time_t timer;
    time(&timer);
    struct tm *time = localtime(&timer);
    s = time->tm_sec;
    h = time->tm_hour;
    m = time->tm_min;
    printf("%s %02d:%02d:%02d ", Log_prefix, h, m, s);
    for (int i = 0; ; i++) {
        if (message[i] != '\n') {
        print(message[i]);
    } else {
        break;
    }
    }
    printf("\n");
}
