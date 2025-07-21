#include <stdio.h>

int f(int a) {
    if (a > 1000)
        return a - 4;
    else
        return f(f(a + 5));
}

int main(void) {
    printf("%d", f(15));
    return 0;
}