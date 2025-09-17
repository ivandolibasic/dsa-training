// fgetc() - same as getc() which can be implemented as macro, fgetc() is always a function (safer)

#include <stdio.h>

int main() {
    FILE *f = fopen("input.txt", "r");
    char c = fgetc(f);
    printf("Output %c", c);
    return 0;
}