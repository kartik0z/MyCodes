class Vehicle {
    public void startEngine() {
        System.out.println("Vehicle engine started.");
    }
}

class Car extends Vehicle {
    @Override
    public void startEngine() {
        super.startEngine();
        System.out.println("Car engine started with a roar.");
    }
}

class Bike extends Vehicle {
    @Override
    public void startEngine() {
        System.out.println("Bike engine started with a vroom.");
    }
}

public class VehicleDemo {
    public static void main(String[] args) {
        Vehicle vehicle = new Vehicle();
        vehicle.startEngine();

        Car car = new Car();
        car.startEngine();

        Bike bike = new Bike();
        bike.startEngine();
    }
}
