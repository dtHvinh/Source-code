#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

void displayArray(int arr[]){
    for(int i = 0 ; arr[i+1] != '\0' ;i++){
        printf("%d " , arr[i]);
    }
}

int main(){
    int arr[] = {1,2,3,4};
    int *p = arr;
    
    displayArray(p);
}


