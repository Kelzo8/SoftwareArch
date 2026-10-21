#pragma once
#include <memory>
#include <string>
#include <vector>
class GreetingStyle { public: virtual ~GreetingStyle() = default; virtual std::string generate(const std::string& name) const = 0; };
class FriendlyGreeting final : public GreetingStyle { public: std::string generate(const std::string& name) const override; };
class FormalGreeting final : public GreetingStyle { public: std::string generate(const std::string& name) const override; };
class PirateGreeting final : public GreetingStyle { public: std::string generate(const std::string& name) const override; };
std::string validate_name(const std::string& name);
