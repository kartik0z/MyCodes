#include <stdio.h>
#include <conio.h>

void main(){
    float num1,num2, total;
    printf("Enter the value for num1 and num2: ");
    scanf("%f%f", &num1, &num2);

    total = num1+num2;

    if(total/2==0){
        printf("It is a even number!\n");
    } else{
        printf("It is a odd number!\n");
    }
    getch();
}