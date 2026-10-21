#ifndef IO_H
#define IO_H
#include <stdio.h>
int read_line(FILE *in, char *buffer, size_t size);
void present(FILE *out, const char *message);
#endif
