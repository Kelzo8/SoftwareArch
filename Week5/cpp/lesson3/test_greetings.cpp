#include "greetings.hpp"
#include "application.hpp"
#include <cassert>
class FakeInput:public InputProvider{public:std::string read_name()override{return "Ada";}std::string read_style(const std::vector<std::string>&)override{return "friendly";}};
class FakePresenter:public Presenter{public:std::string value;void show(const std::string&s)override{value=s;}};
int main(){FriendlyGreeting f;FormalGreeting g;PirateGreeting p;assert(f.generate("Ada")=="Hello, Ada!");assert(g.generate("Ada").find("Good day")==0);assert(p.generate("Ada").find("Ahoy")==0);bool bad=false;try{validate_name(" ");}catch(...){bad=true;}assert(bad);FakeInput i;FakePresenter o;std::map<std::string,std::shared_ptr<const GreetingStyle>> m{{"friendly",std::make_shared<FriendlyGreeting>()}};Application app(i,o,m);app.run();assert(o.value=="Hello, Ada!");}
