#include "../lib/stack.h"

int push(stack *root, long double value) {
  int flag = False;
  struct stack *insert = calloc(1, sizeof(struct stack));
  if (insert != NULL) {
    struct stack *temp = root;
    while (temp->top != NULL) {
      temp = temp->top;
    }
    insert->value = value;
    insert->top = NULL;
    temp->top = insert;
  } else {
    flag = True;
  }
  return flag;
}

long double pop(stack *root) {
  struct stack *temp = root;
  while (temp->top->top != NULL) {
    temp = temp->top;
  }
  struct stack *val = temp->top;
  temp->top = temp->top->top;
  long double value = val->value;
  free(val);
  return value;
}

long double peak(stack *root) {
  struct stack *temp = root;
  while (temp->top != NULL) {
    temp = temp->top;
  }
  long double value = temp->value;
  return value;
}

void read(stack *root) {
  struct stack *temp = root;
  do {
    printf("%f\n", temp->value);
    temp = temp->top;
  } while (temp != NULL);
}

void destroy(struct stack *root) {
  struct stack *temp = root;
  if (temp->top != NULL) destroy(root->top);
  free(root);
}

int count_stack(stack *root) {
  long double value = 0;
  struct stack *temp = root;
  while (temp->top != NULL) {
    temp = temp->top;
    value++;
  }
  return value;
}