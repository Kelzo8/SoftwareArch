#include "greetings.hpp"
#include <algorithm>
#include <cctype>
#include <stdexcept>
std::string FriendlyGreeting::generate(const std::string& n) const { return "Hello, " + n + "!"; }
std::string FormalGreeting::generate(const std::string& n) const { return "Good day, " + n + ". It is a pleasure to meet you."; }
std::string PirateGreeting::generate(const std::string& n) const { return "Ahoy, " + n + "! Welcome aboard!"; }
std::string validate_name(const std::string& n) { if(n.find_first_not_of(" \t\r\n")==std::string::npos) throw std::invalid_argument("Please enter a non-empty name."); return n; }
