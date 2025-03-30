abstract class Shape {
    abstract void draw();
}

class Circle extends Shape implements Resizable {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public void draw() {
        System.out.println("Drawing a Circle with radius: " + radius);
    }

    @Override
    public void resize(double factor) {
        radius *= factor;
        System.out.println("Resized Circle to new radius: " + radius);
    }
}

class Rectangle extends Shape {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public void draw() {
        System.out.println("Drawing a Rectangle with width: " + width + " and height: " + height);
    }
}

interface Resizable {
    void resize(double factor);
}

public class ShapeDemo {
    public static void main(String[] args) {
        Circle circle = new Circle(5);
        circle.draw();
        circle.resize(2);
        circle.draw();

        Rectangle rectangle = new Rectangle(4, 6);
        rectangle.draw();
    }
}