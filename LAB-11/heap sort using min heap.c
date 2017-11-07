#include<stdio.h>
#include<stdlib.h>

//swap

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

// To add a new node to a heaped tree

void Heapify(int i, int *array,int heapsize) {
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l< heapsize&&array[l]>array[i]){
        largest = l;
    }
    if(r<heapsize&&array[r]>array[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(&array[largest],&array[i]);
        Heapify(largest,array,heapsize);
    }
}


// HeapSort

void heapsort(int *array,int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        Heapify(i,array,n);
    }
    for(i=n-1;i>=0;i--){
        swap(&array[0],&array[i]);
        Heapify(0,array,i);
    }
}

int main(){

    int n,i;
    printf("enter size of heap array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements of heap\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    printf("the sorted heap is\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
 }
