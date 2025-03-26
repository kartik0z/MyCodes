import java.util.Scanner;

public class EvenOddChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Accept a number from the user
        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        // Determine if the number is even or odd using if-else
        if (number % 2 == 0) {
            System.out.println(number + " is Even.");
        } else {
            System.out.println(number + " is Odd.");
        }

        // Print all even numbers from 1 to 100 using a for loop
        System.out.println("\nEven numbers from 1 to 100:");
        for (int i = 1; i <= 100; i++) {
            if (i % 2 == 0) {
                System.out.print(i + " ");
            }
        }
    }
}
