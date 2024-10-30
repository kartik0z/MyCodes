#include <stdio.h>

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {5, 4, 3, 2, 1};
    int sum[5];

    // Adding two arrays
    for(int i = 0; i < 5; i++) {
        sum[i] = arr1[i] + arr2[i];
        printf("Sum of element %d: %d\n", i, sum[i]);
    }

    return 0;
}