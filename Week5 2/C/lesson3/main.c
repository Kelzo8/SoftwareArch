#include "greeting.h"
#include "io.h"
#include <stdio.h>
#include <string.h>

static const GreetingStyle styles[] = {
    {"friendly", friendly_generate},
    {"formal", formal_generate},
    {"pirate", pirate_generate}
};

int main(void) {
    char name[128], choice[32], message[512];
    size_t i;
    const GreetingStyle *selected = NULL;

    fputs("Name: ", stdout);
    if (!read_line(stdin, name, sizeof name) || !valid_name(name)) {
        fputs("Please enter a non-empty name.\n", stderr);
        return 1;
    }
    fputs("Style (friendly/formal/pirate): ", stdout);
    if (!read_line(stdin, choice, sizeof choice)) {
        fputs("Input error.\n", stderr);
        return 1;
    }
    for (i = 0; i < sizeof styles / sizeof styles[0]; ++i) {
        if (strcmp(choice, styles[i].name) == 0) selected = &styles[i];
    }
    if (selected == NULL) {
        fputs("Unknown greeting style.\n", stderr);
        return 1;
    }
    if (!selected->generate(name, message, sizeof message)) {
        fputs("Greeting could not be generated.\n", stderr);
        return 1;
    }
    present(stdout, message);
    return 0;
}
