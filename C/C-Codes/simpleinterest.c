#include <stdio.h>
#include <conio.h>

void main(){
    float p,r,t,si;
    printf("Enter the principle: ");
    scanf("%f",&p);
    printf("Enter the rate: ");
    scanf("%f",&r);
    printf("Enter the time: ");
    scanf("%f",&t);

    si=(p*r*t)/100;

    printf("The simple interest is: %f\n", si);
    getch();
}