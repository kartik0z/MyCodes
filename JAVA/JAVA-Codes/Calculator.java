public class Calculator {

    public int add(int a, int b) {
        System.out.println("Adding two integers: " + a + " + " + b);
        return a + b;
    }

    public double add(double a, double b) {
        System.out.println("Adding two doubles: " + a + " + " + b);
        return a + b;
    }

    public double add(int a, double b) {
        System.out.println("Adding integer and double: " + a + " + " + b);
        return a + b;
    }

    public static void main(String[] args) {
        Calculator calc = new Calculator();

        System.out.println("Result 1: " + calc.add(5, 10));
        System.out.println("Result 2: " + calc.add(5.5, 3.2));
        System.out.println("Result 3: " + calc.add(7, 4.5));
    }
}
