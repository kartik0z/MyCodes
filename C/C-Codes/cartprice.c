#include <stdio.h>
#include <conio.h>

void main(){
    float price;
    printf("Enter the value: ");
    scanf("%f", &price);

    if((price>100)&&(price<=150))
    {
        printf("You get a cashback of 10$.\n");
    }
    else if(price<100)
    {
        printf("Add more items!\n");
    }
    else
    {
        printf("Your cart is empty!\n");
    }
getch();
}