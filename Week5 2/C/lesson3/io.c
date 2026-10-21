#include "io.h"
#include <string.h>
int read_line(FILE *in, char *buffer, size_t size) { if (!fgets(buffer,(int)size,in)) return 0; buffer[strcspn(buffer,"\r\n")]='\0'; return 1; }
void present(FILE *out, const char *message) { fprintf(out,"%s\n",message); }
