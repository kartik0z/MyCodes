#include <stdio.h>

void bubbleSort(int arr[], int length){
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printingElements(int arr[], int length){
    for(int i=0; i<length; i++){
        printf("Array[%d]: %d\n", i, arr[i]);
    }
}

int main(){
    int length;
    int arr[50];

    printf("Enter number of elements for the array: \n");
    scanf("%d", &length);

    arr[length];

    printf("Enter elements for the array: ");
    for(int i; i<length;i++){
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, length);

    printingElements(arr, length);
}