#include <stdio.h>
#include <conio.h>

void main(){
    float s1,s2,s3,s4,s5, total, percent;
    printf("Enter the marks for subject 1-5: ");
    scanf("%f%f%f%f%f", &s1,&s2,&s3,&s4,&s5);

    total = s1+s2+s3+s4+s5;
    percent = total/5;
    if((percent>90)&&(percent<=100))
    {
        printf("\n Your Grade is A+!");
    }
    else if((percent>80)&&(percent<=90))
    {
        printf("\n Your grade is A!");
    }
    else if((percent>70)&&(percent<=80))
    {
        printf("\n Your grade is B+");
    }
    else if((percent>60)&&(percent<=70))
    {
        printf("\n Your grade is C!");
    }
    else if((percent>50)&&(percent<=60))
    {
        printf("\n Your grade is D");
    }
    else if((percent<50)&&(percent>=0))
    {
        printf("Your FAILED!");
    }
    else
    {
        printf("Invalid percent");
    }
    getch();
}