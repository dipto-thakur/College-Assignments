package company.employees;

// Enum defining the fixed set of roles an employee can have.
// Declared public so it's visible to other packages, like company.utils
// and the default-package Main class that uses it.
public enum Role {
    DEVELOPER,
    MANAGER,
    TESTER
}