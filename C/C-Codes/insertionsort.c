#include <stdio.h>

void insertionSort(int a[], int length);

int main()
{

    int a[50];
    int length;

    printf("Enter number of elements for the Array(1-50): ");
    scanf("%d", &length);

    a[length];

    printf("Enter elements for the array: ");
    for(int i=0; i <length; i++)
    {
        scanf("%d", &a[i]);
    }

    insertionSort(a, length);
    for(int i=0; i<length; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
}

void insertionSort(int a[], int length)
{
    for(int i = 1; i <length; i++)
    {
        int Key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j]> Key)
        {
            a[j + 1] = a[j];
            j = j-1;
        }
        a[j + 1] = Key;
    }
}