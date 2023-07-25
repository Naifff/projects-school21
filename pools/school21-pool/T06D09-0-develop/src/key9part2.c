#include <stdio.h>

#define LEN 100
#define FALSE 0
#define TRUE 1
#define ONE 1

int input(int *buffer, int *length);
void sum(const int *buff1, int len1, const int *buff2, int len2, int *result);
void sub(const int *buff1, int len1, const int *buff2, int len2, int *result);
void output(int *buffer, int length);

int main() {
    int buff1[LEN];
    int buff2[LEN];
    int result1[LEN];
    int len1, len2;
    if (input(buff1, &len1) == TRUE) {
        int result_length = len1;
        if (input(buff2, &len2) == TRUE) {
            sum(buff1, len1, buff2, len2, result1);
            output(result1, result_length);
            printf("\n");
            if (len1 > len2) {
                sub(buff1, len1, buff2, len2, result1);
                output(result1, result_length);
                printf("\n");
            } else if (len1 == len2) {
                if (buff1[1] > buff2[1]) {
                    sub(buff1, len1, buff2, len2, result1);
                    output(result1, result_length);
                    printf("\n");
                } else {
                    printf("n/a");
                }
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length) {
    char c;
    buffer[0] = 0;
    int count = 1;
    for (int i = 1; i < LEN; i++) {
        if (scanf("%d%c", &buffer[i], &c) == 2 && buffer[i] <= 9) {
            if (c == '\n') {
                count++;
                *length = count;
                return TRUE;
            } else {
                count++;
            }
        } else {
            return FALSE;
        }
    }
    return FALSE;
}

void null_massive(int *result, int length) {
    for (int i = 0; i < length; i++) {
        result[i] = 0;
    }
}

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result) {
    null_massive(result, len1);
    int index2 = len2 - 1;
    for (int i = len1 - 1; i >= 0; i--) {
        if (index2 != 0) {
            if ((buff1[i] + buff2[index2] + result[i]) / 10 == 1) {
                result[i] = (buff1[i] + buff2[index2] + result[i]) % 10;
                result[i - 1] += 1;
            } else {
                result[i] = buff1[i] + buff2[index2] + result[i];
            }
            index2--;
        } else {
            result[i] = buff1[i];
        }
    }
}

void sub(const int *buff1, int len1, const int *buff2, int len2, int *result) {
     null_massive(result, len1);
     int index2 = len2 - 1;
     for (int i = len1 - 1; i >= 0; i--) {
         if (index2 != 0) {
             if (buff2[index2] > buff1[i]) {
                 result[i] = (buff1[i] + 10 - buff2[index2] + result[i]);
                 result[i - 1] = -1;
             } else {
                 result[i] = (buff1[i] - buff2[index2] + result[i]);
             }
             index2--;
         } else {
             result[i] = buff1[i];
         }
     }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i == 0 && buffer[0] != 0) {
            if (i != (length - 1))
                printf("%d ", buffer[i]);
        } else if (i!= 0) {
            if (i != (length - 1))
                printf("%d ", buffer[i]);
            else
                printf("%d", buffer[i]);
        }
    }
}
