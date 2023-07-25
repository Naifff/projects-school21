#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

#ifdef MACROLEN
#define STR() s21_strlen_test()
#endif  // MACROLEN
#ifdef MACROCMP
#define STR() s21_strcmp_test()
#endif  // MACROCMP
#ifdef MACROCPY
#define STR() s21_strcpy_test()
#endif  // MACROCPY
#ifdef MACROCAT
#define STR() s21_strcat_test()
#endif  // MACROCAT
#ifdef MACROCHR
#define STR() s21_strchr_test()
#endif  // MACROCHR
#ifdef MACROSTR
#define STR() s21_strstr_test()
#endif  // MACROSTR
#ifdef MACROTOK
#define STR() s21_strtok_test()
#endif  // MACROTOK

int main() {
    STR();
    return 0;
}

void s21_strtok_test() {
    int a;
    char *arr = "qwertyiop";
    char *empty = "\0";
    char *empty2 = "";
    char *n = NULL;
    char *str = "rty";
    printf("1 - %s\n", arr);
    a = s21_strtok(arr, str);
    printf("%d\n", a);
    if (a == 6) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("2 - EMPTY LINE WITH NULL STR\n");
    a = s21_strtok(empty, str);
    printf("%d\n", a);
    if (a == -2) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("3 - EMPTY LINE\n");
    a = s21_strtok(empty2, str);
    printf("%d\n", a);
    if (a == -2) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
     printf("4 - NULL\n");
    a = s21_strtok(n, str);
    printf("%d\n", a);
    if (a == -1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
}

void s21_strstr_test() {
    int a;
    char *arr = "qwertyiop";
    char *empty = "\0";
    char *empty2 = "";
    char *n = NULL;
    char *str = "rty";
    printf("1 - %s\n", arr);
    a = s21_strstr(arr, str);
    printf("%d\n", a);
    if (a == 4) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("2 - EMPTY LINE WITH NULL STR\n");
    a = s21_strstr(empty, str);
    printf("%d\n", a);
    if (a == -2) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("3 - EMPTY LINE\n");
    a = s21_strstr(empty2, str);
    printf("%d\n", a);
    if (a == -2) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
     printf("4 - NULL\n");
    a = s21_strstr(n, str);
    printf("%d\n", a);
    if (a == -1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
}

void s21_strchr_test() {
    int a;
    char *arr = "qwerty";
    char *empty = "\0";
    char *empty2 = "";
    char *n = NULL;
    char ch = 'r';
    printf("1 - %s\n", arr);
    a = s21_strchr(arr, ch);
    printf("%d\n", a);
    if (a == 3) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("2 - EMPTY LINE WITH NULL STR\n");
    a = s21_strchr(empty, ch);
    printf("%d\n", a);
    if (a == -2) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("3 - EMPTY LINE\n");
    a = s21_strchr(empty2, ch);
    printf("%d\n", a);
    if (a == -2) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
     printf("4 - NULL\n");
    a = s21_strchr(n, ch);
    printf("%d\n", a);
    if (a == -1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
}

void s21_strcat_test() {
    int a;
    char *arr = "qwerty";
    char *arr2 = "asdfghjk";
    char *empty = "\0";
    char *empty2 = "";
    char *n = NULL;
    printf("1 - %s, %s\n", arr, arr2);
    a = s21_strcat(arr, arr2);
    printf("%d\n", a);
    if (a == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("2 - EMPTY LINE WITH NULL STR, %s\n", arr2);
    a = s21_strcat(empty, arr2);
    printf("%d\n", a);
    if (a == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("3 - EMPTY LINE, %s\n", arr2);
    a = s21_strcat(empty2, arr2);
    printf("%d\n", a);
    if (a == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
     printf("4 - NULL, %s\n", arr2);
    a = s21_strcat(n, arr2);
    printf("%d\n", a);
    if (a == -1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    // free(arr);
}

void s21_strcpy_test() {
    char *arr = "qwerty";
    char *empty = "\0";
    char *empty2 = "";
    char *n = NULL;
    int a;
    printf("1 - %s\n", arr);
    a = s21_strcpy(arr);
    printf("%d\n", a);
    if (a == 1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("2 - EMPTY LINE WITH NULL STR\n");
    a = s21_strcpy(empty);
    printf("%d\n", a);
    if (a == 1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("3 - EMPTY LINE\n");
    a = s21_strcpy(empty2);
    printf("%d\n", a);
    if (a == 1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
     printf("4 - NULL\n");
    a = s21_strcpy(n);
    printf("%d\n", a);
    if (a == -1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    free(arr);
    free(empty);
    free(empty2);
}

void s21_strcmp_test() {
    int a;
    char *arr = "qwerty";
    char *arr2 = "qwertyuiop";
    char *empty = "\0";
    char *empty2 = "";
    char *n = NULL;
    printf("1 - %s, %s\n", arr, arr2);
    a = s21_strcmp(arr, arr2);
    printf("%d\n", a);
    if (a == 3) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("2 - %s, %s\n", arr2, arr);
    a = s21_strcmp(arr2, arr);
    printf("%d\n", a);
    if (a == 2) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("3 - %s, %s\n", arr, arr);
    a = s21_strcmp(arr, arr);
    printf("%d\n", a);
    if (a == 1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("4 - EMPTY LINE WITH NULL STR, %s\n", arr);
    a = s21_strcmp(empty, arr);
    printf("%d\n", a);
    if (a == 3) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("5 - EMPTY LINE, %s\n", arr);
    a = s21_strcmp(empty2, arr);
    printf("%d\n", a);
    if (a == 3) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
     printf("6 - NULL, %s\n", arr);
    a = s21_strcmp(n, arr);
    printf("%d\n", a);
    if (a == -1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
}

void s21_strlen_test() {
    int a;
    char *arr2 = "qwertyuiop";
    char *empty = "\0";
    char *empty2 = "";
    char *n = NULL;
    printf("1 - %s\n", arr2);
    a = s21_strlen(arr2);
    printf("%d\n", a);
    if (a == 10) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("2 - EMPTY LINE WITH NULL STR\n");
    a = s21_strlen(empty);
    printf("%d\n", a);
    if (a == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    a = s21_strlen(empty2);
    printf("3 - EMPTY LINE\n");
    printf("%d\n", a);
    if (a == 0) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
    printf("4 - NULL\n");
    a = s21_strlen(n);
    printf("%d\n", a);
    if (a == -1) { printf("SUCCESS\n");
    } else { printf("FAIL\n");
    }
}
