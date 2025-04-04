import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;

public class FileReadWriteExample {

    public static void main(String[] args) {
        String filePath = "output.txt";
        String contentToWrite = "Hello, this is a test string written to a file!";

        // Writing to the file using FileWriter
        try (FileWriter writer = new FileWriter(filePath)) {
            writer.write(contentToWrite);
            System.out.println("Content written to file successfully.");
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }

        // Reading from the file using FileReader
        try (FileReader reader = new FileReader(filePath)) {
            int character;
            System.out.println("\nContent read from file:");
            while ((character = reader.read()) != -1) {
                System.out.print((char) character);
            }
        } catch (IOException e) {
            System.out.println("Error reading from file: " + e.getMessage());
        }
    }
}

