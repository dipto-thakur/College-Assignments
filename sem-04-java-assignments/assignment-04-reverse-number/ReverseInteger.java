import java.util.Scanner;

public class ReverseInteger {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter an integer to reverse: ");
            int originalNumber = scanner.nextInt();

            int reversedNumber = reverse(originalNumber);

            System.out.println("Original number: " + originalNumber);
            System.out.println("Reversed number: " + reversedNumber);
        }
    }

    private static int reverse(int original) {
        int number = original;
        int reversed = 0;

        while (number != 0) {
            int digit = number % 10;               // extract the last digit
            reversed = reversed * 10 + digit;       // append it to the result
            number /= 10;                           // drop the last digit
        }
        return reversed;
    }
}