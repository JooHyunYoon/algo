#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE    7

typedef enum {false, true} BOOL;

int queue[SIZE];
int front, rear;

BOOL isFull(){
    if(((rear + 1) % SIZE) == front){
        return true;
    }
    return false;
}

BOOL isEmpty(){
    if(rear == front){
        return true;
    }
    return false;
}

void initializeQueue(){
    front = 0;
    rear = 0;
}

void linearEnqueue(int num){
    queue[rear++] = num;

    if(rear >= SIZE){
        rear = 0;
    }
}

int linearDequeue(){
    int num = queue[front++];

    if(front >= SIZE){
        front = 0;
    }
    return num;
}

int circularDequeue(){
    if(isEmpty()){
        return -1;
    }
    int num = queue[front++];

    if(front >= SIZE){
        front = 0;
    }
    return num;
}

void circularEnqueue(int num){
    int returnValue;

    if(isFull()){
        returnValue = circularDequeue();
        printf("returns: %d\n", returnValue);
    }

    queue[rear++] = num;
    if(rear >= SIZE){
        rear = 0;
    }
}

void printQueue(){
    int i;

    for(i = 0; i < SIZE; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    int i;
    initializeQueue();

    // Linear Queue
    for(i = 1; i <= 7; i++){
        linearEnqueue(i);
        printQueue();
    }

    memset(queue, 0, sizeof(int));
    // Circular Queue
    for(i = 1; i <= 20; i++){
        circularEnqueue(i);
        printQueue();
    }
    return 0;
}