import java.util.Map;
import java.util.Set;
public class GreetingTests {
    static class FakeInput implements InputProvider { public String readName(){return "Ada";} public String readStyle(Set<String> styles){return "friendly";} }
    static class FakePresenter implements Presenter { String message; public void show(String value){message=value;} }
    public static void main(String[] args) {
        assert new FriendlyGreeting().generate("Ada").equals("Hello, Ada!");
        assert new FormalGreeting().generate("Ada").startsWith("Good day, Ada.");
        assert new PirateGreeting().generate("Ada").contains("Ahoy");
        boolean rejected=false;try{GreetingApplication.validateName("  ");}catch(IllegalArgumentException e){rejected=true;}assert rejected;
        FakePresenter out=new FakePresenter();new GreetingApplication(new FakeInput(),out,Map.of("friendly",new FriendlyGreeting())).run();assert out.message.equals("Hello, Ada!");
    }
}
