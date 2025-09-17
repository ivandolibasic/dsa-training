// fputc() - putc() can be a macro, fputc is always a function

#include <stdio.h>

int main() {
    char c = 'A';
    FILE *f = fopen("output.txt", "w");
    fputc(c, f);
    return 0;
}