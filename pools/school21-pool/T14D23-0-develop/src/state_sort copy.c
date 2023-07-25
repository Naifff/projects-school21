#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "binary_func.h"

void path_s(char *path, int *flag);
void read(char *path);
void menu();
void print(all binary);
void sort(char *path);
int minmax(FILE *text, int a, int b);

int main() {
    menu();
    return 0;
}

void menu() {
    int menu = 0;
    int flag = 0;
    char *path = malloc(100 * sizeof(char));
    path_s(path, &flag);
    rewind(stdin);
    while (menu != -1) {
        rewind(stdin);
    if (scanf("%d", &menu) == 1) {
    switch (menu) {
        case 0 : read(path); break;
        case 1 : sort(path); read(path); break;
        case 2 :
        break;
        case 3 :
        break;
        default : break;
        }
   
    } else {
        printf("n/a\n");
    }
    }
    free(path);
}

void sort(char *path) {
    int a;
    FILE *text;
    all buf1;
    all buf2;
    if ((text = fopen(path, "rb+")) != NULL) {
        fseek(text, 0, SEEK_END);
        int position = ftell(text);
        fseek(text, 0, SEEK_SET);
           if (position == 0) {
            printf("n/a\n");
           }
           a = get_records_count_in_file(text);
            for (int i = 0; i < a; i++) {
               buf1 = read_record_from_file(text, i); 
                for (int j = i + 1; j < a - 1; j++) {
                    buf2 = read_record_from_file(text, j); 
                    if (minmax(text, buf1.year, buf2.year) == 1)
                        break;
                    if (minmax(text, buf1.month, buf2.month) == 1)
                        break;
                    if (minmax(text, buf1.day, buf2.day) == 1)
                        break;
                    if (minmax(text, buf1.hour, buf2.hour) == 1)
                        break;
                    if (minmax(text, buf1.min, buf2.min) == 1)
                        break;
                    if (minmax(text, buf1.sec, buf2.sec) == 1)
                        break;
                    if (minmax(text, buf1.status, buf2.status) == 1)
                        break;
                    if (minmax(text, buf1.code, buf2.code) == 1)
                        break;
                    }
                    }
        } else {
            printf("n/a\n");
            }
    fclose(text);
}

int minmax(FILE *text, int a, int b) {
    int flag = 0;
    if (a > b) {
        swap_records_in_file(text, a, b);
        a = b;
        flag = 1;
    }
    return flag;
}

void path_s(char *path, int *flag) {
    if (scanf("%s", path) != 1) {
        *flag = 1;
        printf("n/a\a");
        }
}

void read(char *path) {
    FILE *text;
    if ((text = fopen(path, "rb+")) != NULL) {
        fseek(text, 0, SEEK_END);
        int position = ftell(text);
        fseek(text, 0, SEEK_SET);
            if (position == 0) {
            printf("n/a\n");
            }
        int a = get_records_count_in_file(text);
        for (int i = 0; i < a; i++) {
            print(read_record_from_file(text, i));
            }
        printf("\n");
        fclose(text);
    } else {
        printf("n/a\n");
        }
    
}

void print(all binary) {
    printf("%d %d %d %d %d %d %d %d\n", binary.year, binary.month, binary.day,
    binary.hour, binary.min, binary.sec, binary.status, binary.code);
}