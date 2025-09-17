#include <stdio.h>

int rek(char *s) {
    if (s[0] == 0)
        printf("\\");
    else {
        putchar(s[0]);
        if (s[1])
            putchar(s[1]);
        rek(s + 1);
    }
}

int main(void) {
    rek("ABCD");
    return 0;
}