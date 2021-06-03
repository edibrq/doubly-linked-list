#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void push(Node** head, int val){
    Node *temp = (struct Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    if(*head == NULL){
        temp->prev = NULL;
        *head = temp;
        return;
    }

    (*head)->prev = temp;
    temp->next = *head;
    *head = temp;
    temp->prev = NULL;
}

void pop(Node** head, int val){
    if(*head == NULL){
        push(head, val);
        return;
    }

    Node *temp = (struct Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;

    Node *iter = *head;
    while(iter->next != NULL){
        iter = iter->next;
    }
    iter->next = temp;
    temp->prev = iter;
}

void print(Node** head){
    if(*head == NULL){
        return;
    }
    printf("%d ", (*head)->data);
    print(&(*head)->next);
}

int main() {
    Node *head = NULL;
    pop(&head, 3);
    pop(&head, 2);
    pop(&head, 1);
    push(&head, 5);
    print(&head);
}
