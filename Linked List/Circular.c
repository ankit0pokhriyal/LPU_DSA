#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *start = NULL;

void traversal() {
    if (start == NULL) {
        printf("List empty\n");
    } 
    
    else {
    // CODE HERE
    }
}

void insertBeg(int num) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = num;
    if (start == NULL) {
        start = new_node;
        new_node->next = start;
    } else {
    // CODE HERE
    }
}

void insertEnd(int num) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = num;
    if (start == NULL) {
        start = new_node;
        new_node->next = start;
    } else {
        struct Node *ptr = start;
    // CODE HERE
    }
}

void insertAfter(int num, int val) {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }
    // CODE HERE
   
}

void deleteBeg() {
    if (start == NULL) {
        printf("List empty\n");
    } else if (start->next == start) {
        // CODE HERE
 
    } else {
        struct Node *ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        struct Node *temp = start;
       // CODE HERE
        free(temp);
    }
}

void deleteEnd() {
    if (start == NULL) {
        printf("List empty\n");
    } else if (start->next == start) {
        free(start);
        start = NULL;
    } else {
       // CODE HERE
    }
}

void deleteAtPos(int val) {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }
    if (start->next == start && start->data == val) {
        free(start);
        start = NULL;
        return;
    }
    struct Node *preptr = NULL, *ptr = start;
    /* CODE HERE*/ {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr->data == val) {
    // CODE HERE
    } else {
        printf("Value not found\n");
    }
}

int main() {

    return 0;
}
