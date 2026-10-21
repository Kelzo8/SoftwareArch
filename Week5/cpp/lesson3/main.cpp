#include "application.hpp"
#include <iostream>
InputProvider& console_input(); Presenter& console_presenter();
int main(){std::map<std::string,std::shared_ptr<const GreetingStyle>> styles{{"friendly",std::make_shared<FriendlyGreeting>()},{"formal",std::make_shared<FormalGreeting>()},{"pirate",std::make_shared<PirateGreeting>()}};Application app(console_input(),console_presenter(),styles);try{app.run();}catch(const std::exception& e){std::cerr<<"Error: "<<e.what()<<'\n';return 1;}return 0;}
