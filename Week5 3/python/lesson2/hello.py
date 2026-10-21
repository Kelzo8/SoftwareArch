def greeting(name: str) -> str:
    cleaned = name.strip()
    if not cleaned:
        raise ValueError("name cannot be empty")
    return f"Hello, {cleaned}!"

if __name__ == "__main__":
    try:
        name = input("Name: ")
        print(greeting(name))
    except ValueError as error:
        print(f"Error: {error}")
