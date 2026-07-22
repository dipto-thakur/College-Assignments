import java.util.Scanner;

public class EvenOddCounter {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the starting number of the range: ");
            int start = scanner.nextInt();
            System.out.print("Enter the ending number of the range: ");
            int end = scanner.nextInt();

            // swap so the range always reads low to high, regardless of
            // which order the user typed the two numbers in
            if (start > end) {
                int temp = start;
                start = end;
                end = temp;
            }

            int evenCount = 0;
            int oddCount = 0;

            for (int i = start; i <= end; i++) {
                if (i % 2 == 0) {
                    evenCount++;
                } else {
                    oddCount++;
                }
            }

            System.out.println("\nCounting numbers from " + start + " to " + end + ":");
            System.out.println("Number of even numbers: " + evenCount);
            System.out.println("Number of odd numbers: " + oddCount);
        }
    }
}