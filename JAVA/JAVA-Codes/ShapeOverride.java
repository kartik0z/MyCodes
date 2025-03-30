class Shape {
    public double area() {
        System.out.println("Calculating area for a generic shape.");
        return 0;
    }
}

class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double area() {
        double result = Math.PI * radius * radius;
        System.out.println("Area of Circle: " + result);
        return result;
    }
}

class Square extends Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    @Override
    public double area() {
        double result = side * side;
        System.out.println("Area of Square: " + result);
        return result;
    }
}

public class ShapeOverride {
    public static void main(String[] args) {
        Shape shape1 = new Circle(7);
        Shape shape2 = new Square(5);

        System.out.println("Using Polymorphism:");
        shape1.area();
        shape2.area();
    }
} 

