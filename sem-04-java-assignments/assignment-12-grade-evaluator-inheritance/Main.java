import java.util.Scanner;

// Base class
class Student {
    protected String name;
    protected int rollNumber;
    protected double marks;

    public void readDetails(Scanner sc) {
        System.out.print("Enter student name: ");
        name = sc.nextLine();
        System.out.print("Enter roll number: ");
        rollNumber = sc.nextInt();
        System.out.print("Enter marks (out of 100): ");
        marks = sc.nextDouble();
        sc.nextLine();   // consume leftover newline
    }

    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Marks: " + marks);
    }
}

// Derived class, adds grading on top of the inherited student fields
class GradeCalculator extends Student {

    public char calculateGrade() {
        if (marks >= 90) {
            return 'A';
        } else if (marks >= 75) {
            return 'B';
        } else if (marks >= 60) {
            return 'C';
        } else {
            return 'D';
        }
    }
}

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            GradeCalculator student = new GradeCalculator();
            student.readDetails(sc);   // inherited from Student

            char grade = student.calculateGrade();

            System.out.println("\n=== Student Report ===");
            student.displayDetails();   // inherited from Student
            System.out.println("Grade: " + grade);
        }
    }
}