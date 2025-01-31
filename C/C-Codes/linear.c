#include <stdio.h>

// Function for linear search
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);

    if(result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}