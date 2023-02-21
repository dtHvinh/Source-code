#include<stdio.h>
#include<stdlib.h>  
#include<time.h>
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition(int arr[], int left, int right){
    if(left >= right) return -1;
    int l = left;
    int r = right;
    int pivot = arr[left + (right - left) / 2];

    while (l <= r)
    {
        while(arr[l] < pivot) l++;
        while(arr[r] > pivot) r--;
        if(l <= r){
            swap(&arr[l],&arr[r]);
            l++;
            r--;
        }
    }
    return l;   
}

void quicksort(int arr[], int left, int right){
    int l = partition(arr,left,right);
    if(l != -1){
        quicksort(arr,left,l-1);
        quicksort(arr,l,right);
    }
}

int main() {
    int arr[] = {1,4,6,2,3,5,7,9,8};
    quicksort(arr,0,8);

    for (size_t i = 0; i < 9; i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}

