#pragma once
#include <string>
#include <vector>
class InputProvider { public: virtual ~InputProvider()=default; virtual std::string read_name()=0; virtual std::string read_style(const std::vector<std::string>& names)=0; };
class Presenter { public: virtual ~Presenter()=default; virtual void show(const std::string& message)=0; };
