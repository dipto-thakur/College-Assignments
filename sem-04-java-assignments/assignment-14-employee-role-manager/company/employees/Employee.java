package company.employees;

// Represents one employee: a name and a Role from the enum above.
// Public so classes outside this package (company.utils, and the
// default-package Main class) can create and use it.
public class Employee {
    private final String name;
    private final Role role;

    public Employee(String name, Role role) {
        this.name = name;
        this.role = role;
    }

    public String getName() {
        return name;
    }

    public Role getRole() {
        return role;
    }

    @Override
    public String toString() {
        return name + " (" + role + ")";
    }
}