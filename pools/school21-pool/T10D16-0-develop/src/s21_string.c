#include "s21_string.h"
#include <stdlib.h>
#include <stdio.h>

int s21_strlen(char *arr) {
    int a;
    char *n = NULL;
    if (arr == n) {
        a = -1;
    } else {
    for (int i = 0; ; i++) {
        if (arr[i] == '\0') {
            a = i;
            break;
     }
    }
    }
    return a;
}

int s21_strcmp(char *str1, char *str2) {
    int a, b;
    int flag = 0;
    char *n = NULL;
    if (str1 == n || str2 == n) {
        flag = -1;
    } else {
    a = s21_strlen(str1);
    b = s21_strlen(str2);
    if (a == b) {
        flag = 1;
    } else if (a > b) {
        flag = 2;
    } else {
        flag = 3;
    }
    }
    return flag;
}

int s21_strcpy(char *arr) {
    int a = 1;
    char *copyarr;
    if (((copyarr = malloc(s21_strlen(arr) * sizeof(char))) != NULL)) {
    char *n = NULL;
    if (arr == n) {
        a = -1;
    } else {
    for (int i = 0; ; i++) {
        copyarr[i] = arr[i];
        if (copyarr[i] != arr[i]) {
            a = -1;
        }
        if (arr[i] == '\0') {
            break;
     }
    }
    }
    free(copyarr);
    } else {
        a = -1;
    }
    return a;
}

int s21_strcat(char *arr, char *arr2) {
    int flag = 0, a, b;
    char *newarr;
    char *n = NULL;
    a = s21_strlen(arr);
    b = s21_strlen(arr2);
    if (((newarr = malloc((a + b) * sizeof(char))) != NULL)) {
        if (arr == n || arr2 == n) {
        flag = -1;
    } else {
        for (int i = 0; i < a; i++) {
            newarr[i] = arr[i];
            if (newarr[i] != arr[i]) {
                a = -1;
                }
        }
        for (int j = a; j < (a + b); j++) {
            newarr[j] = arr2[j - a];
            if (newarr[j] != arr2[j - a]) {
                a = -1;
                }
                }
    }
    int c = s21_strlen(newarr);
    if (c != a + b) {
        flag = -1;
    }
    free(newarr);
} else {
        flag = -1;
    }
    return flag;
}

int s21_strchr(char *arr, char ch) {
    int flag = -2;
    char *n = NULL;
    int c = s21_strlen(arr);
    if (arr == n) {
        flag = -1;
    } else {
    for (int i = 0; i < c; i++) {
        if (arr[i] == ch)
        flag = i;
        if (arr[i] == '\0') {
            break;
     }
    }
    }
    return flag;
}

int s21_strstr(char *arr, char *str) {
    int flag = -2, count = 0;
    char *n = NULL;
    int c = s21_strlen(arr);
    int b = s21_strlen(str);
    if (arr == n) {
        flag = -1;
    } else {
    for (int i = 0; i < c; i++) {
        if (arr[i] == str[0]) {
            flag = i + 1;
        for (int j = 0; j < b; j++) {
            if (arr[i + j] == str[j]) {
                count++;
            } else {
                count = 0;
            }
        }
        }
        }
    if (count == b)
    flag = flag;
    else
    flag = -2;
    }
    return flag;
}

int s21_strtok(char *arr, char *str) {
    int flag = -2, count = 0;
    char *n = NULL;
    int c = s21_strlen(arr);
    int b = s21_strlen(str);
    if (arr == n) {
        flag = -1;
    } else {
    for (int i = 0; i < c; i++) {
        if (arr[i] == str[0]) {
            flag = i + b;
        for (int j = 0; j < b; j++) {
            if (arr[i + j] == str[j]) {
                count++;
            } else {
                count = 0;
            }
        }
        }
        }
    if (count == b)
    flag = flag;
    else
    flag = -2;
    }
    return flag;
}
