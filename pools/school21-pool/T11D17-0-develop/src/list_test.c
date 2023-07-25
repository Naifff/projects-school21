#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "door_struct.h"
#include <time.h>

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void add_test(struct door* doors, struct node* elem);
void rem_test(struct node* elem, struct node* root);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors, DOORS_COUNT);
    struct node* test = init(&doors[0]);
    add_test(&doors[11], test);
    rem_test(find_door(doors[11].id, test), test);
    destroy(test);
    return 0;
}

void rem_test(struct node* elem, struct node* root) {
    if (remove_door(elem, root) == NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void add_test(struct door* doors, struct node* elem) {
    if (add_door(elem, doors) != NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
