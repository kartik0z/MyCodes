// Shared resource class
class Counter {
    private int count = 0;

    // Synchronized method to increment counter
    public synchronized void increment() {
        count++;
    }

    public int getCount() {
        return count;
    }
}

// Thread class that increments the counter
class CounterThread extends Thread {
    private Counter counter;

    public CounterThread(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 1000; i++) {
            counter.increment();
        }
    }
}

public class SynchronizedCounterDemo {
    public static void main(String[] args) {
        Counter sharedCounter = new Counter();

        // Create multiple threads accessing the same counter
        CounterThread t1 = new CounterThread(sharedCounter);
        CounterThread t2 = new CounterThread(sharedCounter);
        CounterThread t3 = new CounterThread(sharedCounter);

        // Start the threads
        t1.start();
        t2.start();
        t3.start();

        // Wait for threads to finish
        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted");
        }

        // Display the final value of the counter
        System.out.println("Final Counter Value: " + sharedCounter.getCount());
    }
}
