#ifndef SRC_STACK_H_
#define SRC_STACK_H_

struct stack {
    int element;
    struct stack* top;
};

struct stack* init(int n);
struct stack* push(struct stack* test, int n);
struct stack* pop(struct stack* test);
void destroy(struct stack* test);

#endif  // SRC_STACK_H_
