#pragma once
#include "greetings.hpp"
#include "ports.hpp"
#include <map>
class Application { InputProvider& input_; Presenter& presenter_; const std::map<std::string,std::shared_ptr<const GreetingStyle>>& styles_; public: Application(InputProvider&,Presenter&,const std::map<std::string,std::shared_ptr<const GreetingStyle>>&); void run(); };
