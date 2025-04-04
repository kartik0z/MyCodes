// Main class
public class MultiThreadDemo {

    // First thread: Print numbers 1 to 5 with delay
    static class NumberThreadWithDelay extends Thread {
        public void run() {
            try {
                for (int i = 1; i <= 5; i++) {
                    System.out.println("Delayed Number: " + i);
                    Thread.sleep(1000); // 1-second delay
                }
            } catch (InterruptedException e) {
                System.out.println("NumberThreadWithDelay interrupted");
            }
        }
    }

    // Second thread: Print numbers 1 to 5 without delay
    static class NumberThread extends Thread {
        public void run() {
            for (int i = 1; i <= 5; i++) {
                System.out.println("NumberThread: " + i);
                try {
                    Thread.sleep(500); // small delay for better output visibility
                } catch (InterruptedException e) {
                    System.out.println("NumberThread interrupted");
                }
            }
        }
    }

    // Third thread: Print letters A to E
    static class LetterThread extends Thread {
        public void run() {
            for (char ch = 'A'; ch <= 'E'; ch++) {
                System.out.println("LetterThread: " + ch);
                try {
                    Thread.sleep(500); // small delay for better output visibility
                } catch (InterruptedException e) {
                    System.out.println("LetterThread interrupted");
                }
            }
        }
    }

    public static void main(String[] args) {
        // First, run a thread with delay
        System.out.println("Starting NumberThreadWithDelay...");
        Thread t1 = new NumberThreadWithDelay();
        t1.start();

        try {
            t1.join(); // wait for t1 to finish before starting others
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted");
        }

        // Now run two threads concurrently
        System.out.println("\nStarting NumberThread and LetterThread concurrently...");
        Thread t2 = new NumberThread();
        Thread t3 = new LetterThread();

        t2.start();
        t3.start();
    }
}