#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

int top;
int stack[6];

bool isFull(){
    if(top > 5){
        return true;
    }
    return false;
}

bool isEmpty(){
    if(top < 0){
        return true;
    }
    return false;
}

void push(int num){
    if(isFull()){
        return;
    }
    stack[top] = num;
    top++;
    if(top == 6){
        top = 5;
    }
}

int pop(){
    if(isEmpty()){
        return -1;
    }
    int num;
    num = stack[top];
    stack[top] = 0;
    top--;

    return num;
}

int main(){
    int i, num;
    for(i = 1; i <= 6; i++) {
        push(i);
    }

    printf("PUSH\n");
    for(i = 0; i < 6; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");

    printf("POP\n");
    for(i = 0; i < 6; i++){
        num = pop();
        printf("%d\n", num);
    }

    return 0;
}