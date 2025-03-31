public class Student {
    private String name;
    private int age;
    private double[] marks;

    // Constructor to initialize properties
    public Student(String name, int age, double[] marks) {
        this.name = name;
        this.age = age;
        this.marks = marks;
    }

    // Method to calculate the average marks
    public double calculateAverageMarks() {
        double sum = 0;
        for (double mark : marks) {
            sum += mark;
        }
        return marks.length > 0 ? sum / marks.length : 0;
    }

    // Method to display student details
    public void displayDetails() {
        System.out.println("Student Name: " + name);
        System.out.println("Age: " + age);
        System.out.print("Marks: ");
        for (double mark : marks) {
            System.out.print(mark + " ");
        }
        System.out.println("\nAverage Marks: " + calculateAverageMarks());
    }

    public static void main(String[] args) {
        // Creating a Student object with sample data
        double[] marks = {85.5, 90.0, 78.5, 88.0};
        Student student = new Student("John Doe", 20, marks);

        // Displaying student details
        student.displayDetails();
    }
}