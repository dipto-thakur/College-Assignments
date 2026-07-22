import java.util.Scanner;

class Student {
    private final String name;
    private final int rollNumber;
    private final String grade;

    // Constructor 1: name + roll number only, grade defaults
    Student(String name, int rollNumber) {
        this(name, rollNumber, "Not Assigned");   // constructor chaining
    }

    // Constructor 2: name + roll number + grade
    Student(String name, int rollNumber, String grade) {
        this.name = name;
        this.rollNumber = rollNumber;
        this.grade = grade;
    }

    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Grade: " + grade);
        System.out.println("--------------------------");
    }
}

public class Main {
    public static void main(String[] args) {
        // A couple of hardcoded objects just to show both constructors working
        Student s1 = new Student("Alice", 101);              // 2-arg constructor
        Student s2 = new Student("Bob", 102, "A");            // 3-arg constructor

        System.out.println("== Hardcoded Students ==");
        s1.displayDetails();
        s2.displayDetails();

        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("== Create Student (2-arg constructor) ==");
            System.out.print("Enter name: ");
            String name1 = sc.nextLine();
            System.out.print("Enter roll number: ");
            int roll1 = sc.nextInt();
            sc.nextLine();   // consume leftover newline
            Student s3 = new Student(name1, roll1);

            System.out.println("== Create Student (3-arg constructor) ==");
            System.out.print("Enter name: ");
            String name2 = sc.nextLine();
            System.out.print("Enter roll number: ");
            int roll2 = sc.nextInt();
            sc.nextLine();   // consume leftover newline
            System.out.print("Enter grade: ");
            String grade2 = sc.nextLine();
            Student s4 = new Student(name2, roll2, grade2);

            System.out.println("== Entered Students ==");
            s3.displayDetails();
            s4.displayDetails();
        }
    }
}