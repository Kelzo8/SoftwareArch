from typing import Protocol

class GreetingStyle(Protocol):
    def generate(self, name: str) -> str: ...

class FriendlyGreeting:
    def generate(self, name: str) -> str:
        return f"Hello, {name}!"

class FormalGreeting:
    def generate(self, name: str) -> str:
        return f"Good day, {name}. It is a pleasure to meet you."

class PirateGreeting:
    def generate(self, name: str) -> str:
        return f"Ahoy, {name}! Welcome aboard!"

def validate_name(name: str) -> str:
    cleaned = name.strip()
    if not cleaned:
        raise ValueError("Please enter a non-empty name.")
    return cleaned
