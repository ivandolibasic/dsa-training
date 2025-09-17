// fgets() - safer than gets(), reads n-1 characters until \n from file or stdin, adds \0 at the end

#include <stdio.h>

int main() {
    char text[20];
    printf("Input: ");
    fgets(text, 20, stdin);
    printf("Output: %s", text);
    return 0;
}