import java.util.Scanner;

// Base class
class Animal {
    void makeSound() {
        System.out.println("Some sound...");
    }
}

class Dog extends Animal {
    @Override
    void makeSound() {
        System.out.println("Woof Woof!");
    }
}

class Cat extends Animal {
    @Override
    void makeSound() {
        System.out.println("Meow Meow!");
    }
}

class Cow extends Animal {
    @Override
    void makeSound() {
        System.out.println("Moo Moo!");
    }
}

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter the animal name (dog/cat/cow): ");
            String choice = sc.nextLine().trim().toLowerCase();

            // declared as Animal, but the actual object created below
            // decides which makeSound() runs, that's runtime polymorphism
            Animal animal;

            switch (choice) {
                case "dog":
                    animal = new Dog();
                    break;
                case "cat":
                    animal = new Cat();
                    break;
                case "cow":
                    animal = new Cow();
                    break;
                default:
                    animal = new Animal();   // fallback to the base class
                    System.out.println("Unknown animal, using default sound.");
            }

            animal.makeSound();
        }
    }
}