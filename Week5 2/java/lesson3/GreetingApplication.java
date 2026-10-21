import java.util.Map;
final class GreetingApplication {
    private final InputProvider input; private final Presenter presenter; private final Map<String,GreetingStyle> styles;
    GreetingApplication(InputProvider input, Presenter presenter, Map<String,GreetingStyle> styles) { this.input=input; this.presenter=presenter; this.styles=Map.copyOf(styles); }
    void run() { String name=validateName(input.readName()); String key=input.readStyle(styles.keySet()); GreetingStyle style=styles.get(key); if(style==null) throw new IllegalArgumentException("Unknown greeting style."); presenter.show(style.generate(name)); }
    static String validateName(String name) { if(name==null || name.isBlank()) throw new IllegalArgumentException("Please enter a non-empty name."); return name.strip(); }
}
