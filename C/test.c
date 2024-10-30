#include <stdio.h>

int main(){
    int a, b, c;

    printf("Enter the values for a:\n");
    scanf("%d", &a);
    printf("Enter the values for b:\n");
    scanf("%d", &b);
    printf("Enter the values for c:\n");
    scanf("%d", &c);

    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    if (max == a)
        printf("A is greater,");
    else if (max == b)
        printf("B is greater,");
    else
        printf("C is greater.");

    return 0;
}