import java.util.Scanner;

// Base class, holds what every library item has in common
abstract class LibraryItem {
    protected String title;
    protected String author;

    public void readCommonDetails(Scanner sc) {
        System.out.print("Enter title: ");
        title = sc.nextLine();
        System.out.print("Enter author: ");
        author = sc.nextLine();
    }

    abstract void displayDetails();
}

// A contract for anything that can be checked out. LibraryItem itself
// doesn't implement this, since not every kind of item necessarily has
// to be borrowable, that decision is left to each subclass.
interface Borrowable {
    void borrowItem();
}

// Derived class 1
class Book extends LibraryItem implements Borrowable {
    private int pages;
    private boolean borrowed = false;

    public void readBookDetails(Scanner sc) {
        readCommonDetails(sc);
        System.out.print("Enter number of pages: ");
        pages = sc.nextInt();
        sc.nextLine();   // consume leftover newline
    }

    @Override
    public void borrowItem() {
        borrowed = true;
        System.out.println("\"" + title + "\" has been borrowed.");
    }

    @Override
    void displayDetails() {
        System.out.println("Book: " + title + " by " + author);
        System.out.println("Pages: " + pages);
        System.out.println("Status: " + (borrowed ? "Borrowed" : "Available"));
    }
}

// Derived class 2
class Magazine extends LibraryItem implements Borrowable {
    private int issueNumber;
    private boolean borrowed = false;

    public void readMagazineDetails(Scanner sc) {
        readCommonDetails(sc);
        System.out.print("Enter issue number: ");
        issueNumber = sc.nextInt();
        sc.nextLine();   // consume leftover newline
    }

    @Override
    public void borrowItem() {
        borrowed = true;
        System.out.println("\"" + title + "\" (Issue #" + issueNumber + ") has been borrowed.");
    }

    @Override
    void displayDetails() {
        System.out.println("Magazine: " + title + " by " + author);
        System.out.println("Issue Number: " + issueNumber);
        System.out.println("Status: " + (borrowed ? "Borrowed" : "Available"));
    }
}

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("=== Enter Book Details ===");
            Book book = new Book();
            book.readBookDetails(sc);

            System.out.println("\n=== Enter Magazine Details ===");
            Magazine magazine = new Magazine();
            magazine.readMagazineDetails(sc);

            // borrow just the book, to show one item's status changing
            // while the other stays available
            System.out.println();
            book.borrowItem();

            System.out.println("\n=== Library Catalog ===");
            book.displayDetails();
            System.out.println("--------------------------");
            magazine.displayDetails();
        }
    }
}