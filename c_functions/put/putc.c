// putc() - writes single character in a file or stream

#include <stdio.h>

int main() {
    char c = 'A';
    FILE *f = fopen("output.txt", "w");
    putc(c, f);
    return 0;
}