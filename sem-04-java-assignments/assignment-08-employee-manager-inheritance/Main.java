import java.util.Scanner;

// Base class
class Employee {
    protected String name;
    protected double salary;

    public void readEmployeeDetails(Scanner sc) {
        System.out.print("Enter employee name: ");
        name = sc.nextLine();
        System.out.print("Enter employee salary: ");
        salary = sc.nextDouble();
        sc.nextLine();   // consume leftover newline
    }

    public void displayEmployeeDetails() {
        System.out.println("Employee Name: " + name);
        System.out.println("Employee Salary: " + salary);
    }
}

// Derived class, inherits name and salary from Employee
class Manager extends Employee {
    private String department;

    public void readManagerDetails(Scanner sc) {
        readEmployeeDetails(sc);   // reuse the base class's reading logic
        System.out.print("Enter manager department: ");
        department = sc.nextLine();
    }

    public void displayManagerDetails() {
        displayEmployeeDetails();   // reuse the base class's display logic
        System.out.println("Manager Department: " + department);
    }
}

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("=== Enter Employee Details ===");
            Employee emp = new Employee();
            emp.readEmployeeDetails(sc);

            System.out.println("\n=== Enter Manager Details ===");
            Manager mgr = new Manager();
            mgr.readManagerDetails(sc);

            System.out.println("\n=== Employee Information ===");
            emp.displayEmployeeDetails();

            System.out.println("\n=== Manager Information ===");
            mgr.displayManagerDetails();
        }
    }
}