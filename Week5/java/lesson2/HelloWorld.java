import java.util.Scanner;

public class HelloWorld {
    static String greeting(String name) {
        if (name == null || name.isBlank()) throw new IllegalArgumentException("name cannot be empty");
        return "Hello, " + name.strip() + "!";
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); System.out.print("Name: ");
        try { System.out.println(greeting(input.nextLine())); }
        catch (IllegalArgumentException e) { System.err.println(e.getMessage()); System.exit(1); }
    }
}
