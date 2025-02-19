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
    } else {
        struct Node *ptr = start;
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void insertBeg(int num) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
}

void insertEnd(int num) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->next = NULL;
    
    if (start == NULL) {
        start = new_node;
    } else {
        struct Node *ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void insertAfter(int num, int val) {
    struct Node *ptr = start;
    while (ptr != NULL) {
        if (ptr->data == val) {
            struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = num;
            new_node->next = ptr->next;
            ptr->next = new_node;
            return;
        }
        ptr = ptr->next;
    }
    printf("Value not found\n");
}

void deleteBeg() {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node *temp = start;
    start = start->next;
    free(temp);
}

void deleteEnd() {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }
    if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }
    struct Node *ptr = start, *preptr = NULL;
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}

void deleteAtPos(int val) {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }
    if (start->data == val) {
        deleteBeg();
        return;
    }
    struct Node *ptr = start, *preptr = NULL;
    while (ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Value not found\n");
        return;
    }
    preptr->next = ptr->next;
    free(ptr);
}

int main() {
    insertBeg(1);
    insertBeg(2);
    insertEnd(3);
    insertEnd(4);
    insertAfter(5, 3);
    traversal();

    deleteBeg();
    traversal();

    deleteEnd();
    traversal();

    deleteAtPos(3);
    traversal();

    deleteAtPos(1);
    traversal();

    deleteAtPos(5);
    traversal();

    return 0;
}
