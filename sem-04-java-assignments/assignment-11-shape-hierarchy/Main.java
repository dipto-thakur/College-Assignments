import java.util.Scanner;

// Abstract base class, can't be instantiated directly
abstract class Shape {
    abstract void displayArea();
}

class Rectangle extends Shape {
    private final double length;
    private final double width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    void displayArea() {
        double area = length * width;
        System.out.println("Rectangle area: " + area);
    }
}

class Square extends Shape {
    private final double side;

    Square(double side) {
        this.side = side;
    }

    @Override
    void displayArea() {
        double area = side * side;
        System.out.println("Square area: " + area);
    }
}

class Circle extends Shape {
    private final double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    void displayArea() {
        double area = Math.PI * radius * radius;
        System.out.println("Circle area: " + area);
    }
}

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter length and width of rectangle: ");
            double length = sc.nextDouble();
            double width = sc.nextDouble();

            System.out.print("Enter side of square: ");
            double side = sc.nextDouble();

            System.out.print("Enter radius of circle: ");
            double radius = sc.nextDouble();

            // an array of the abstract type, holding three different concrete shapes
            Shape[] shapes = {
                new Rectangle(length, width),
                new Square(side),
                new Circle(radius)
            };

            System.out.println("\nDisplaying areas polymorphically:");
            for (Shape shape : shapes) {
                shape.displayArea();   // resolved at runtime based on the actual object
            }
        }
    }
}