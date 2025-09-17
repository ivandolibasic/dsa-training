// strlen() - returns number of characters without \0

#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "text";
    printf("Text length: %d", strlen(text));
    return 0;
}