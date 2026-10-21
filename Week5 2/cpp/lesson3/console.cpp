#include "ports.hpp"
#include <iostream>
class ConsoleInput final : public InputProvider { public: std::string read_name() override { std::string s; std::cout<<"Name: "; std::getline(std::cin,s); return s; } std::string read_style(const std::vector<std::string>& names) override { std::cout<<"Styles:"; for(auto& n:names)std::cout<<" "<<n; std::cout<<"\nStyle: ";std::string s;std::getline(std::cin,s);return s; } };
class ConsolePresenter final : public Presenter { public: void show(const std::string& s) override { std::cout<<s<<'\n'; } };
InputProvider& console_input(){static ConsoleInput x;return x;} Presenter& console_presenter(){static ConsolePresenter x;return x;}
