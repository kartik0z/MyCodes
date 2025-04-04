import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class FileByteReader {

    public static void main(String[] args) {
        String filePath = "example.txt";

        FileInputStream fis = null;

        try {
            fis = new FileInputStream(filePath);

            int byteData;

            System.out.println("File contents:");

            while ((byteData = fis.read()) != -1) {
                System.out.print((char) byteData);
            }

        } catch (FileNotFoundException e) {
            System.out.println("Error: File not found - " + filePath);
        } catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        } finally {
            if (fis != null) {
                try {
                    fis.close();
                } catch (IOException e) {
                    System.out.println("Error closing the file: " + e.getMessage());
                }
            }
        }
    }
}