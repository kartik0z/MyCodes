public class ArrayOperations {
    public static void main(String[] args) {
        // Initialize an array of integers
        int[] numbers = {12, 45, 78, 34, 89, 23, 56};

        int sum = 0;
        int largest = numbers[0];

        // Calculate sum and find the largest value
        for (int number : numbers) {
            sum += number;
            if (number > largest) {
                largest = number;
            }
        }

        // Calculate the average
        double average = (double) sum / numbers.length;

        // Display results
        System.out.println("Array: ");
        for (int number : numbers) {
            System.out.print(number + " ");
        }
        System.out.println("\nSum: " + sum);
        System.out.println("Average: " + average);
        System.out.println("Largest Value: " + largest);
    }
}

