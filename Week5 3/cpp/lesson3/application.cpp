#include "application.hpp"
#include <stdexcept>
Application::Application(InputProvider& i,Presenter& p,const std::map<std::string,std::shared_ptr<const GreetingStyle>>& s):input_(i),presenter_(p),styles_(s){}
void Application::run(){auto name=validate_name(input_.read_name());std::vector<std::string> keys;for(const auto& item:styles_)keys.push_back(item.first);auto key=input_.read_style(keys);auto it=styles_.find(key);if(it==styles_.end())throw std::invalid_argument("Unknown greeting style.");presenter_.show(it->second->generate(name));}
