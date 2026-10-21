#include "greeting.h"
#include <assert.h>
#include <string.h>

int main(void) {
    char message[128];
    assert(friendly_generate("Ada", message, sizeof message));
    assert(strcmp(message, "Hello, Ada!") == 0);
    assert(formal_generate("Ada", message, sizeof message));
    assert(strstr(message, "Good day") != NULL);
    assert(pirate_generate("Ada", message, sizeof message));
    assert(strstr(message, "Ahoy") != NULL);
    assert(valid_name("Ada"));
    assert(!valid_name("  "));
    assert(!friendly_generate("Ada", message, 2));
    return 0;
}
