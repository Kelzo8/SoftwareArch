class ConsoleInput:
    def read_name(self) -> str:
        return input("Name: ")
    def read_style(self, available: tuple[str, ...]) -> str:
        print("Styles: " + ", ".join(available))
        return input("Style: ").strip().lower()

class ConsolePresenter:
    def show(self, message: str) -> None:
        print(message)
