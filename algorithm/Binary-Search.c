#include <stdio.h>
#include <stdlib.h>

#define SIZE    7

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *arr, int start, int end){
    if(start >= end){
        return;
    }

    int left = start + 1;
    int right = end;
    int pivot = arr[start];

    while(1){
        while(arr[left] <= pivot){
            left++;
        }
        
        while(arr[right] > pivot){
            right--;
        }

        if(left > right){
            break;
        }

        swap(&arr[left], &arr[right]);
    }
    swap(&arr[start], &arr[right]);

    quickSort(arr, start, right - 1);
    quickSort(arr, right + 1, end);
}

void printArr(int *arr){
    int i;
    for(i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int bSearch(int *arr, int target, int start, int end){
    if(start > end) return -1;

    int mid = (start + end) / 2;
    if(target == arr[mid])
        return mid;
    else if(target < arr[mid])
        return bSearch(arr, target, start, mid - 1);
    else
        return bSearch(arr, target, mid + 1, end);
    
}

int main(){
    int Buf[SIZE] = {3, 45, 5, 8, 23, 67, 13};

    quickSort(Buf, 0, SIZE - 1);
    printArr(Buf);
    printf("index: %d\n", bSearch(Buf, 45, 0, SIZE - 1));
    
    return 0;
}