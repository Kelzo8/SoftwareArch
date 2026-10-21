from greetings import GreetingStyle, validate_name

class Application:
    def __init__(self, input_provider, presenter, styles: dict[str, GreetingStyle]):
        self._input = input_provider
        self._presenter = presenter
        self._styles = styles

    def run(self) -> None:
        name = validate_name(self._input.read_name())
        style_name = self._input.read_style(tuple(self._styles))
        style = self._styles.get(style_name)
        if style is None:
            raise ValueError("Unknown greeting style.")
        self._presenter.show(style.generate(name))
