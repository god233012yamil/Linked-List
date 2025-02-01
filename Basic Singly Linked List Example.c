#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return; // Memory allocation failed
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void delete(int value) {
    Node *temp = head, *prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev != NULL) prev->next = temp->next;
    else head = temp->next;
    free(temp);
}

void traverse() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    printf("Linked List: ");
    traverse();
    delete(20);
    printf("After Deletion: ");
    traverse();
    return 0;
}