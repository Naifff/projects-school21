#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push_test(struct stack* test, int n);
void pop_test(struct stack* test);

int main() {
int n = 13;
struct stack* test = init(6);
push_test(test, n);
pop_test(test);
destroy(test);
}

void pop_test(struct stack* test) {
    if (pop(test) != NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void push_test(struct stack* test, int n) {
    if (push(test, n) != NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}
