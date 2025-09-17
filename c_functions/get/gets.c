// gets() - reads a line from stdin and stores in the string, dangerous because it doesn't check array size which causes buffer overflow

#include <stdio.h>

int main() {
    char text[20];
    printf("Input: ");
    gets(text);
    printf("Output: %s", text);
    return 0;
}