// sscanf() - reads from string as if it's stdin, useful for text parsing

#include <stdio.h>

int main() {
    char text[] = "123 4.56 text";
    int a;
    float b;
    char c[10];
    sscanf(text, "%d %f %s", &a, &b, &c);
    printf("a = %d\n", a);
    printf("b = %.2f\n", b);
    printf("c = %s", c);
    return 0;
}