#include <stdio.h>
#include <string.h>

int main(void) {
    char name[128];
    fputs("Name: ", stdout);
    if (!fgets(name, sizeof name, stdin)) { fputs("Input error\n", stderr); return 1; }
    name[strcspn(name, "\r\n")] = '\0';
    if (name[0] == '\0') { fputs("Name cannot be empty\n", stderr); return 1; }
    printf("Hello, %s!\n", name);
    return 0;
}
