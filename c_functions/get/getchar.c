// getchar() - reads first single character from stdin, doesn't need parameter, returns ASCII value of the character

#include <stdio.h>

int main() {
    printf("Input: ");
    char c = getchar();
    printf("Output: %c", c);
    return 0;
}