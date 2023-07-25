#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "binary_func.h"

void search(char *path);
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    char *path = malloc(100 * sizeof(char));
    if (scanf("%s", path) != 1) {
        printf("n/a\a");
        }
    search(path);
    free(path);
}


void search(char *path) {
    int day, month, year, flag = 0, a;
    FILE *text;
    if ((text = fopen(path, "r")) != NULL) {
    if ((text = fopen(path, "ab+")) != NULL) {
        fseek(text, 0, SEEK_END);
        int position = ftell(text);
        fseek(text, 0, SEEK_SET);
           if (position == 0) {
            printf("n/a\n");
           }
           scanf("%02d.%02d.%04d", &day, &month, &year);
           a = get_records_count_in_file(text);
           for (int i = 0; i < a; i++) {
               if (read_record_from_file(text, i).year == year
               && read_record_from_file(text, i).month == month
               && read_record_from_file(text, i).day == day) {
                   printf("%d", read_record_from_file(text, i).code);
                   flag = 1;
                   break;
               }
           }
           if (flag == 0) {
    printf("n/a\n");
    }
           } else {
    printf("n/a\n");
        }
    } else {
        printf("n/a\n");
    }
fclose(text);
}
