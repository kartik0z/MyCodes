class Account {
    private static int totalAccounts = 0;
    private String accountHolderName;
    private double balance;

    public Account(String accountHolderName, double initialBalance) {
        this.accountHolderName = accountHolderName;
        this.balance = initialBalance;
        totalAccounts++;
    }

    private double calculateBalance() {
        return balance;
    }

    public double getBalance() {
        return calculateBalance();
    }

    public final void displayAccountDetails() {
        System.out.println("Account Holder: " + accountHolderName);
        System.out.println("Balance: $" + getBalance());
        System.out.println("Total Accounts: " + totalAccounts);
    }

    public static int getTotalAccounts() {
        return totalAccounts;
    }
}

class SavingsAccount extends Account {
    private double interestRate;

    public SavingsAccount(String accountHolderName, double initialBalance, double interestRate) {
        super(accountHolderName, initialBalance);
        this.interestRate = interestRate;
    }

    protected void displayInterestRate() {
        System.out.println("Interest Rate: " + interestRate + "%");
    }
}

public class BankApplication {
    public static void main(String[] args) {
        Account acc1 = new Account("John Doe", 1500);
        SavingsAccount acc2 = new SavingsAccount("Jane Smith", 3000, 4.5);

        System.out.println("--- Account Details ---");
        acc1.displayAccountDetails();

        System.out.println("\n--- Savings Account Details ---");
        acc2.displayAccountDetails();
        acc2.displayInterestRate();

        System.out.println("\nTotal Accounts Created: " + Account.getTotalAccounts());
    }
}