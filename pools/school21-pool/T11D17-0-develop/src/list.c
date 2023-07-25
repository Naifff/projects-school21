#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"
#include "list.h"


struct node* init(struct door* door) {
    struct node* root;
    if (door != NULL) {
    root = malloc(sizeof(struct node));
    root->door_value = door;
    root -> next = NULL;
    } else {
        root = NULL;
    }
    return root;
}
struct node* add_door(struct node* elem, struct door* door) {
    struct node* insert;
    if (elem != NULL && door != NULL) {
        insert = malloc(sizeof(struct node));
        insert -> door_value = door;
        insert -> next = elem -> next;
        elem -> next = insert;
    } else {
        insert = NULL;
    }
    return insert;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* temp = root;
    while (temp -> next != NULL) {
    if (temp->door_value->id == door_id) {
        return temp;
    } else {
    temp = temp->next;
    }
}
return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* temp = root;
    while (temp -> next != NULL) {
        if (temp->next == elem) {
            temp->next = elem->next;
            free(elem);
            return root;
        } else {
            temp = temp->next;
        }
    }
    return NULL;
}

void destroy(struct node* root) {
    struct node* temp = root;
    if (temp -> next != NULL)
    destroy(root->next);
    free(root);
}
