// Procedural Programming Approach
import java.util.Scanner;

public class ProceduralVsOOP {

    // Procedural method to calculate area of rectangle
    public static double calculateRectangleArea(double length, double width) {
        return length * width;
    }

    // Procedural method to calculate area of circle
    public static double calculateCircleArea(double radius) {
        return Math.PI * radius * radius;
    }

    // Object-Oriented Programming Approach
    abstract static class Shape {
        abstract double calculateArea();
    }

    static class Rectangle extends Shape {
        double length, width;

        Rectangle(double length, double width) {
            this.length = length;
            this.width = width;
        }

        @Override
        double calculateArea() {
            return length * width;
        }
    }

    static class Circle extends Shape {
        double radius;

        Circle(double radius) {
            this.radius = radius;
        }

        @Override
        double calculateArea() {
            return Math.PI * radius * radius;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Procedural approach
        System.out.println("Procedural Approach:");
        System.out.print("Enter length of rectangle: ");
        double length = scanner.nextDouble();
        System.out.print("Enter width of rectangle: ");
        double width = scanner.nextDouble();
        System.out.println("Area of Rectangle: " + calculateRectangleArea(length, width));

        System.out.print("Enter radius of circle: ");
        double radius = scanner.nextDouble();
        System.out.println("Area of Circle: " + calculateCircleArea(radius));

        // Object-Oriented approach
        System.out.println("\nObject-Oriented Approach:");
        Rectangle rect = new Rectangle(length, width);
        Circle circ = new Circle(radius);

        System.out.println("Area of Rectangle: " + rect.calculateArea());
        System.out.println("Area of Circle: " + circ.calculateArea());
    }
}