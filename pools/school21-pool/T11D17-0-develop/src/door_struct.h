#ifndef SRC_DOOR_STRUCT_H_
#define SRC_DOOR_STRUCT_H_

struct door {
    int id;
    int status;
};

void close(struct door *doors, int n);
void sort(struct door *doors, int n);
void output(struct door *doors, int n);

#endif  // SRC_DOOR_STRUCT_H_
