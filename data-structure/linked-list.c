#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char Data;
    struct node *next;
} NODE;

NODE *head, *tail;

void initialize(){
    head = (NODE *)malloc(sizeof(NODE));
    tail = (NODE *)malloc(sizeof(NODE));

    head->Data = 0;
    tail->Data = 0;

    head->next = tail;
    tail->next = NULL;
}

void insertNode(char n){
    NODE *index = head;
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->Data = n;
    newNode->next = NULL;

    while(index->next != tail){
        index = index->next;
    }

    index->next = newNode;
    newNode->next = tail;
    head->Data = head->Data + 1;
}

void deleteNode(char n){
    NODE *index = head;
    NODE *delNode = (NODE *)malloc(sizeof(NODE));

    while(index->next->Data != n){
        index = index->next;
    }

    delNode = index->next;
    index->next = delNode->next;
    
    head->Data = head->Data - 1;
    free(delNode);
}

void printNode(){
    int i;
    NODE *index = head;

    for(i = 0; i <= head->Data + 1; i++){
        if(index != head && index != tail){
            printf("%d ", index->Data);
        }
        index = index->next;
    }

    printf("\n");
}

int main(){
    int i;
    initialize();

    // insert data
    for(i = 1; i <= 5; i++){
        insertNode(i);
    }

    printNode();

    // delete 3
    deleteNode(3);
    printNode();

    return 0;
}