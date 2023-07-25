#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "logger.h"

void menu();
void read(char *path);
void add(char *path);
void encrypt(char *path);
void logs(int menu, char *path);

#ifdef MACROQ5
#define Q5() logs(menu, path)
#endif  // MACROQ5

int main() {
    menu();
    return 0;
}

void menu() {
    int menu = 0;
    char *path = malloc(100 * sizeof(char));
    while (menu != -1) {
        rewind(stdin);
        if (scanf("%d", &menu) == 1) {
    switch (menu) {
        case 1 : read(path);
        #ifdef MACROQ5
        Q5();
        #endif  // MACROQ5
        break;
        case 2 : add(path);
        #ifdef MACROQ5
        Q5();
        #endif  // MACROQ5
        break;
        case 3 : encrypt(path);
        #ifdef MACROQ5
        Q5();
        #endif  // MACROQ5
        break;
        default : break;
        }
    } else {
        printf("n/a\n");
    }
    }
    free(path);
}
#ifdef MACROQ5
void logs(int menu, char *path) {
    FILE *init;
    init = log_init();
    char *new = malloc(10 * sizeof(char));
    char *mess = malloc(10 * sizeof(char));
    switch (menu) {
        case 1 :
        strcat(new, "[INFO] ");
        strcat(mess, "open");
        logcat(init, new, mess, path); log_close(init); break;
        case 2 :
        strcat(new, "[INFO] ");
        strcat(mess, "changed");
        logcat(init, new, mess, path); log_close(init); break;
        case 3 :
        strcat(new, "[WARNING] ");
        strcat(mess, "encrypt");
        logcat(init, new, mess, path); log_close(init); break;
        default : break;
    }
    free(mess);
    free(new);
}
#endif  // MACROQ5

void read(char *path) {
    FILE *text;
    char c;
if (scanf("%s", path) != 1) {
        printf("n/a\n");
        } else {
            if ((text = fopen(path, "r")) != NULL) {
                fseek(text, 0, SEEK_END);
                int position = ftell(text);
                fseek(text, 0, SEEK_SET);
                 if (position == 0) {
                    printf("n/a\n");
                } else {
                while (fscanf(text, "%c", &c) != EOF) {
                        printf("%c", c);
                }
                printf("\n");
                fclose(text);
                }
            } else {
                printf("n/a\n");
                }
                }
}

void encrypt(char *path) {
    DIR *folder;
    FILE *text;
    FILE *encr;
    char c;
    int a;
    struct dirent *dir;
    if (scanf("%s", path) != 1) {
        printf("n/a\n");
    } else {
        printf("Choose shift size\n");
        scanf("%d", &a);
        if ((folder = opendir(path)) != NULL) {
            while ((dir = readdir(folder)) != NULL) {
                char* str = calloc(100, sizeof(char));
                strcpy(str, path);
                str = strcat(str, "/");
                str = strcat(str, dir->d_name);
                if (strcmp(strrchr(dir->d_name, '.'), ".h") == 0) {
                    if ((text = fopen(str, "w")) != NULL) {  // удаление хэдеров
                        fclose(text);
                    } else {
                        printf("n/a\n");
                    }
                } else if (strcmp(strrchr(dir->d_name, '.'), ".c") == 0) {
                    if ((text = fopen(str, "r")) != NULL) {
                        encr = fopen("encr.txt", "w");
                    while (fscanf(text, "%c", &c) == 1) {
                        c = c + a;
                        fputc(c, encr);
                    }
                    fclose(encr);
                    encr = fopen("encr.txt", "r");
                    if ((text = fopen(str, "w")) != NULL) {
                        while (fscanf(encr, "%c", &c) == 1) {
                        fputc(c, text);
                        }
                        remove("encr.txt");
                    } else {
                        printf("n/a\n");
                    }
                    fclose(text);
                }
                }
                free(str);
            }
            closedir(folder);
        } else {
            printf("n/a\n");
        }
    }
}

void add(char *path) {
    FILE *text;
    char c;
    char *new = malloc(100 * sizeof(char));
    if (scanf("%s", new) == 1) {
    if ((text = fopen(path, "a")) != NULL) {
            fputs(new, text);
            fclose(text);
            if ((text = fopen(path, "r")) != NULL) {
                while (fscanf(text, "%c", &c) == 1) {
                        printf("%c", c);
                }
            } else {
                printf("n/a\n");
                }
                printf("\n");
                fclose(text);
                } else {
                    printf("n/a\n");
                }
    } else {
        printf("n/a\n");
    }
    free(new);
}
