import java.util.Map;
public class Main {
    public static void main(String[] args) {
        GreetingApplication app=new GreetingApplication(new ConsoleInput(),new ConsolePresenter(),Map.of("friendly",new FriendlyGreeting(),"formal",new FormalGreeting(),"pirate",new PirateGreeting()));
        try { app.run(); } catch(IllegalArgumentException e) { System.err.println("Error: "+e.getMessage()); System.exit(1); }
    }
}
