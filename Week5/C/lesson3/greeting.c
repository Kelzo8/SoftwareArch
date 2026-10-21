#include "greeting.h"
#include <ctype.h>
#include <stdio.h>

int valid_name(const char *name) {
    if (name == NULL) return 0;
    while (*name != '\0') {
        if (!isspace((unsigned char)*name)) return 1;
        ++name;
    }
    return 0;
}

static int format_greeting(char *output, size_t output_size, const char *format, const char *name) {
    if (output == NULL || name == NULL || output_size == 0) return 0;
    int written = snprintf(output, output_size, format, name);
    return written >= 0 && (size_t)written < output_size;
}

int friendly_generate(const char *name, char *output, size_t output_size) {
    return format_greeting(output, output_size, "Hello, %s!", name);
}
int formal_generate(const char *name, char *output, size_t output_size) {
    return format_greeting(output, output_size, "Good day, %s. It is a pleasure to meet you.", name);
}
int pirate_generate(const char *name, char *output, size_t output_size) {
    return format_greeting(output, output_size, "Ahoy, %s! Welcome aboard!", name);
}
