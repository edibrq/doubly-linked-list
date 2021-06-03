#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

Node* getNewNode(int val){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

int size(Node** head){
    int size = 0;
    if(*head == NULL)
        return 0;
    Node *temp = *head;
    size = 1;
    do{
        ++size;
        temp = temp->next;
    }while(temp->next != NULL);
    return size;
}

void push(Node** head, int val){
    Node *temp = getNewNode(val);
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

    Node *temp = getNewNode(val);

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

void deleteByPos(Node** head, int pos){
    Node *temp = *head;
    for (int i = 0; i < pos - 1; ++i) {
        temp = temp->next;
    }

    printf("deleted value is:%d\n", temp->data);

    if(pos == size(head)){
        temp->prev->next = NULL;
        free(temp);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

int main() {
    Node *head = NULL;
    pop(&head, 3);
    pop(&head, 2);
    pop(&head, 1);
    push(&head, 5);
    printf("size of list is:%d\n",size(&head));
    print(&head);
    deleteByPos(&head, 4);
    printf("\n");
    print(&head);
}
