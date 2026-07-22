package company.utils;

import company.employees.Employee;

import java.util.Comparator;
import java.util.List;

// Utility class that knows how to sort and print employees, kept in its
// own package (company.utils) separate from where Employee and Role
// themselves live (company.employees). This is the "package visibility"
// half of the assignment, this class has to import company.employees.Employee
// to use it at all, since a class in one package can't see classes in
// another package unless they're imported and declared public.
public class EmployeeUtils {

    // Sorts by role name alphabetically (DEVELOPER, MANAGER, TESTER),
    // and by name within the same role, using java.util's Comparator
    public static void sortByRole(List<Employee> employees) {
        employees.sort(
            Comparator.comparing((Employee e) -> e.getRole().name())
                      .thenComparing(Employee::getName)
        );
    }

    public static void printAll(List<Employee> employees) {
        for (Employee e : employees) {
            System.out.println(e);
        }
    }
}