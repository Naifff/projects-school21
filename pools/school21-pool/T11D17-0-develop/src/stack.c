#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack* init(int n) {
    struct stack* root;
    root = malloc(sizeof(struct stack));
    root -> element = n;
    root -> top = NULL;
    return root;
}
struct stack* push(struct stack* test, int n) {
    struct stack* insert;
    insert = malloc(sizeof(struct stack));
        struct stack* tmp = test;
        while (tmp->top != NULL) {
            tmp = tmp->top;
        }
        insert -> element = n;
        insert -> top = NULL;
        tmp->top = insert;

    return insert;
}

struct stack* pop(struct stack* test) {
    struct stack* temp = test;
    while (temp->top->top != NULL) {
        temp = temp->top;
    }
    struct stack* val = temp->top;
    temp->top = temp->top->top;
    free(val);
    return test;
}

void destroy(struct stack* test) {
    struct stack* temp = test;
    if (temp -> top != NULL)
    destroy(test->top);
    free(test);
}
