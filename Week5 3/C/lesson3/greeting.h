#ifndef GREETING_H
#define GREETING_H
#include <stddef.h>

typedef int (*GreetingGenerator)(const char *name, char *output, size_t output_size);
typedef struct GreetingStyle {
    const char *name;
    GreetingGenerator generate;
} GreetingStyle;

int friendly_generate(const char *name, char *output, size_t output_size);
int formal_generate(const char *name, char *output, size_t output_size);
int pirate_generate(const char *name, char *output, size_t output_size);
int valid_name(const char *name);
#endif
