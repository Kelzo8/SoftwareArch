# C++ Activity 3

Build and run from this directory:

```sh
c++ -std=c++17 -Wall -Wextra main.cpp greetings.cpp application.cpp console.cpp -o greeting
./greeting
```

Build and run the non-interactive tests:

```sh
c++ -std=c++17 -Wall -Wextra test_greetings.cpp greetings.cpp application.cpp -o test_greetings
./test_greetings
```

Add a class implementing `GreetingStyle`, then register it in `main.cpp`. `Application` uses the strategy, input, and presenter abstractions and does not depend on console I/O.
