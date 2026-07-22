import java.util.Scanner;

public class SumOfDigits {

    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            System.out.print("Enter a positive integer: ");
            int number = input.nextInt();

            if (number <= 0) {
                System.out.println("Invalid input! Please enter a positive integer.");
                return;
            }

            int sum = sumDigits(number);
            System.out.println("The sum of digits of " + number + " is: " + sum);
        }
    }

    private static int sumDigits(int number) {
        int sum = 0;
        while (number > 0) {
            int digit = number % 10;   // last digit
            sum += digit;
            number /= 10;              // drop the last digit
        }
        return sum;
    }
}