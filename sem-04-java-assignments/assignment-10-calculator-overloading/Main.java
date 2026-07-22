import java.util.Scanner;

class Calculator {
    // Add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Add two double values
    double add(double a, double b) {
        return a + b;
    }
}

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            Calculator calc = new Calculator();

            System.out.println("Enter two integers to add:");
            int int1 = sc.nextInt();
            int int2 = sc.nextInt();
            System.out.println("Result (int + int): " + calc.add(int1, int2));

            System.out.println("\nEnter three integers to add:");
            int int3 = sc.nextInt();
            int int4 = sc.nextInt();
            int int5 = sc.nextInt();
            System.out.println("Result (int + int + int): " + calc.add(int3, int4, int5));

            System.out.println("\nEnter two decimal numbers to add:");
            double dbl1 = sc.nextDouble();
            double dbl2 = sc.nextDouble();
            System.out.println("Result (double + double): " + calc.add(dbl1, dbl2));
        }
    }
}