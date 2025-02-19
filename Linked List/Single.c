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
        do {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != start);
        printf("\n");
    }
}

void insertBeg(int num) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = num;
    if (start == NULL) {
        start = new_node;
        new_node->next = start;
    } else {
        struct Node *ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
        start = new_node;
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
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
    }
}

void insertAfter(int num, int val) {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = num;
    struct Node *ptr = start;
    do {
        if (ptr->data == val) {
            new_node->next = ptr->next;
            ptr->next = new_node;
            return;
        }
        ptr = ptr->next;
    } while (ptr != start);

    printf("Value not found\n");
    free(new_node); 
}
void deleteBeg() {
    if (start == NULL) {
        printf("List empty\n");
    } else if (start->next == start) {
        free(start);
        start = NULL;
    } else {
        struct Node *ptr = start;
        while (ptr->next != start) {
            ptr = ptr->next;
        }
        struct Node *temp = start;
        start = start->next;
        ptr->next = start;
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
        struct Node *ptr = start;
        struct Node *preptr = NULL;
        while (ptr->next != start) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = start;
        free(ptr);
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
    do {
        if (ptr->data == val) {
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
    } while (ptr != start);

    if (ptr->data == val) {
        if (ptr == start) {
            deleteBeg();
        } else {
            if (ptr->next == start) {
                deleteEnd();
            } else {
                preptr->next = ptr->next;
                free(ptr);
            }
        }
    } else {
        printf("Value not found\n");
    }
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