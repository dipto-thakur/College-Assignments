import java.util.Scanner;

public class AreaCalculator {

    // Overloaded method for a circle
    public static double calculateArea(double radius) {
        return Math.PI * radius * radius;
    }

    // Overloaded method for a rectangle
    public static double calculateArea(double length, double width) {
        return length * width;
    }

    // Overloaded method for a triangle
    // The boolean flag exists purely so this method has a different
    // signature from the rectangle version above (two doubles isn't
    // enough on its own to tell them apart at compile time)
    public static double calculateArea(double base, double height, boolean isTriangle) {
        return 0.5 * base * height;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Choose a shape to calculate the area:");
            System.out.println("1. Circle");
            System.out.println("2. Rectangle");
            System.out.println("3. Triangle");
            System.out.print("Enter your choice (1/2/3): ");
            int choice = sc.nextInt();

            double area;

            switch (choice) {
                case 1:
                    System.out.print("Enter radius of the circle: ");
                    double radius = sc.nextDouble();
                    area = calculateArea(radius);
                    System.out.printf("Area of the Circle: %.2f%n", area);
                    break;

                case 2:
                    System.out.print("Enter length of the rectangle: ");
                    double length = sc.nextDouble();
                    System.out.print("Enter width of the rectangle: ");
                    double width = sc.nextDouble();
                    area = calculateArea(length, width);
                    System.out.printf("Area of the Rectangle: %.2f%n", area);
                    break;

                case 3:
                    System.out.print("Enter base of the triangle: ");
                    double base = sc.nextDouble();
                    System.out.print("Enter height of the triangle: ");
                    double height = sc.nextDouble();
                    area = calculateArea(base, height, true);
                    System.out.printf("Area of the Triangle: %.2f%n", area);
                    break;

                default:
                    System.out.println("Invalid choice! Please choose 1, 2 or 3.");
            }
        }
    }
}