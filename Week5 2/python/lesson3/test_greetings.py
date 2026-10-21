import unittest
from greetings import FriendlyGreeting, FormalGreeting, PirateGreeting, validate_name
from application import Application

class FakeInput:
    def __init__(self, name, style): self.name, self.style = name, style
    def read_name(self): return self.name
    def read_style(self, available): return self.style
class FakePresenter:
    def __init__(self): self.messages = []
    def show(self, message): self.messages.append(message)

class GreetingTests(unittest.TestCase):
    def test_two_styles(self):
        self.assertEqual(FriendlyGreeting().generate("Ada"), "Hello, Ada!")
        self.assertTrue(FormalGreeting().generate("Ada").startswith("Good day, Ada."))
    def test_added_pirate_style(self): self.assertIn("Ahoy", PirateGreeting().generate("Ada"))
    def test_blank_name_rejected(self):
        with self.assertRaises(ValueError): validate_name("  ")
    def test_application_without_keyboard(self):
        presenter = FakePresenter()
        app = Application(FakeInput("Ada", "friendly"), presenter, {"friendly": FriendlyGreeting()})
        app.run()
        self.assertEqual(presenter.messages, ["Hello, Ada!"])
    def test_invalid_style_rejected(self):
        app = Application(FakeInput("Ada", "unknown"), FakePresenter(), {"friendly": FriendlyGreeting()})
        with self.assertRaises(ValueError): app.run()

if __name__ == "__main__": unittest.main()
