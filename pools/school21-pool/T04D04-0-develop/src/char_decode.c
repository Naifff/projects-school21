#include <stdio.h>

int coding();
int decoding();

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (*argv[1] == '0') {
            coding();
            return 0;
        } else if (*argv[1] == '1') {
            decoding();
            return 0;
        } else {
            printf("n/a");
            return 0;
        }
    } else {
        printf("n/a");
        return 0;
    }
}

int coding() {
    unsigned char c;
    char probel;
    while (scanf("%c%c", &c, &probel) == 2) {
        if (probel == ' ') {
            printf("%X ", (unsigned int)c);
        } else if (probel == '\n') {
            printf("%X", (unsigned int)c);
            return 0;
        } else {
            printf("n/a");
            return 0;
        }
    }
    return 0;
}

int decoding() {
    unsigned int c;
    unsigned char probel;
    while (scanf("%2X%c", &c, &probel) == 2) {
        if (probel == ' ') {
            printf("%c ", (unsigned char)c);
        } else if (probel == '\n') {
            printf("%c", (unsigned char)c);
            return 0;
        } else {
            printf("n/a");
            return 0;
        }
    }
    printf("n/a");
    return 0;
}
