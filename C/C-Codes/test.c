#include <stdio.h>

float balance=1000.0;

void TotalBalance();
void WithdrawingMoney();
void DepositMoney();

int main(){
    int pin, choice, CorrectPin=1234;
    
    printf("Welcome to the ATM!\n");
    printf("Please enter your pin:\n");
    scanf("%d", &pin);

    if(pin==CorrectPin){
        do{
            printf("<======ATM MENU======>\n");
            printf("1. Check Balance\n");
            printf("2. Withdraw Money\n");
            printf("3. Deposit Money\n");
            printf("4. Exit\n");
            printf("Put in your choice:\n");
            scanf("%d", &choice);

            switch(choice){
                case 1: TotalBalance();
                    break;
                case 2: WithdrawingMoney();
                    break;
                case 3: DepositMoney();
                    break;
                case 4: printf("Thank you for visiting our ATM!\n");
                    break;
                default: printf("Invalid choice");
            }
        }while(choice!=4);
    }else{
        printf("Invalid Pin! Try again!");
    }
    return 0;
}

void TotalBalance(){
    printf("Your total balance is: %.2f\n", balance);
}

void DepositMoney() {
    float deposit;
    printf("Enter the amount to deposit: $");
    scanf("%f", &deposit);
    if (deposit > 0) {
        balance += deposit;
        printf("Deposit successful! Your new balance is: $%.2f\n", balance);
    } else {
        printf("Invalid amount. Deposit failed.\n");
    }
}

void WithdrawingMoney() {
    float withdraw;
    printf("Enter the amount to withdraw: $");
    scanf("%f", &withdraw);
    if (withdraw > 0 && withdraw <= balance) {
        balance -= withdraw;
        printf("Withdrawal successful! Your new balance is: $%.2f\n", balance);
    } else if (withdraw > balance) {
        printf("Insufficient balance. Withdrawal failed.\n");
    } else {
        printf("Invalid amount. Withdrawal failed.\n");
    }
}