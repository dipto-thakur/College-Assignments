import java.util.Scanner;

public class FactorialCalculator {

    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            System.out.print("Enter a non-negative integer: ");
            int number = input.nextInt();

            if (number < 0) {
                System.out.println("Invalid input! Factorial is not defined for negative numbers.");
                return;
            }

            long factorial = calculateFactorial(number);
            System.out.println("Factorial of " + number + " is: " + factorial);
        }
    }

    private static long calculateFactorial(int number) {
        long factorial = 1;
        for (int i = 1; i <= number; i++) {
            factorial *= i;
        }
        return factorial;
    }
}