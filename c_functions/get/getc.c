// getc() - reads first single character from a file or stream

#include <stdio.h>

int main() {
    FILE *f = fopen("input.txt", "r");
    char c = getc(f);
    printf("Output: %c", c);
    return 0;
}