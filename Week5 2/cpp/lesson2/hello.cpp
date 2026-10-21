#include <iostream>
#include <string>
#include <stdexcept>

std::string greeting(const std::string& name) {
    if (name.find_first_not_of(" \t\r\n") == std::string::npos) throw std::invalid_argument("name cannot be empty");
    return "Hello, " + name + "!";
}
int main() {
    std::string name; std::cout << "Name: ";
    if (!std::getline(std::cin, name)) { std::cerr << "Input error\n"; return 1; }
    try { std::cout << greeting(name) << '\n'; } catch (const std::invalid_argument& e) { std::cerr << e.what() << '\n'; return 1; }
}
