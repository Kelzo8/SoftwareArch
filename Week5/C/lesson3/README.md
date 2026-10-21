# C Activity 3

Build and run from this directory:

```sh
cc -std=c11 -Wall -Wextra -pedantic main.c greeting.c io.c -o greeting
./greeting
```

Run the non-interactive tests:

```sh
cc -std=c11 -Wall -Wextra -pedantic test_greeting.c greeting.c -o test_greeting
./test_greeting
```

A new style provides a `GreetingGenerator` function that writes into a caller-owned buffer and reports whether the complete message fit. Add its name and function to the `styles` table in `main.c`. The application does not own greeting storage and the generator module has no shared mutable buffer.
