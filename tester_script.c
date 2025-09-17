#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // char buffer[100];
    // fgets(buffer, 100, stdin); // e.g. we enter ABCDEF\n
    // // buffer = ['A', 'B', 'C', 'D', 'E', 'F', '\n', '\0']
    // // buffer[strlen(buffer) - 1] = '\0';
    // printf("Print: %d", strlen(buffer));

    // char line[] = "123 45.6 A";
    // int x;
    // float y;
    // char c;
    // sscanf(line, "%d %f %c", &x, &y, &c);
    // printf("%d %.1f %c\n", x, y, c);

    char *ch = "Welcome Greeks";
    // putchar(ch);
    puts(ch);
    return 0;
}