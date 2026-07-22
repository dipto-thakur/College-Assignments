import company.employees.Employee;
import company.employees.Role;
import company.utils.EmployeeUtils;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("How many employees do you want to enter? ");
            int count = sc.nextInt();
            sc.nextLine();   // consume leftover newline

            List<Employee> employees = new ArrayList<>();

            for (int i = 1; i <= count; i++) {
                System.out.println("\nEmployee " + i + ":");
                System.out.print("  Name: ");
                String name = sc.nextLine();

                Role role = readRole(sc);
                employees.add(new Employee(name, role));
            }

            System.out.println("\n=== Employees, entry order ===");
            EmployeeUtils.printAll(employees);

            EmployeeUtils.sortByRole(employees);

            System.out.println("\n=== Employees, sorted by role ===");
            EmployeeUtils.printAll(employees);
        }
    }

    // Keeps asking until the user types a role name that actually exists
    // in the Role enum, so a typo doesn't crash the program.
    private static Role readRole(Scanner sc) {
        while (true) {
            System.out.print("  Role (DEVELOPER / MANAGER / TESTER): ");
            String input = sc.nextLine().trim().toUpperCase();
            try {
                return Role.valueOf(input);
            } catch (IllegalArgumentException e) {
                System.out.println("  Not a valid role, please try again.");
            }
        }
    }
}