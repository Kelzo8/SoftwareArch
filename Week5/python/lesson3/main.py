from application import Application
from console import ConsoleInput, ConsolePresenter
from greetings import FriendlyGreeting, FormalGreeting, PirateGreeting

def main() -> None:
    app = Application(ConsoleInput(), ConsolePresenter(), {
        "friendly": FriendlyGreeting(), "formal": FormalGreeting(), "pirate": PirateGreeting()
    })
    try:
        app.run()
    except ValueError as error:
        print(f"Error: {error}")

if __name__ == "__main__":
    main()
