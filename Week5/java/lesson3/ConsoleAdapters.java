import java.util.Scanner;
final class ConsoleInput implements InputProvider { private final Scanner scanner=new Scanner(System.in); public String readName(){System.out.print("Name: ");return scanner.nextLine();} public String readStyle(java.util.Set<String> styles){System.out.println("Styles: "+String.join(", ",styles));System.out.print("Style: ");return scanner.nextLine().strip().toLowerCase();} }
final class ConsolePresenter implements Presenter { public void show(String message){System.out.println(message);} }
