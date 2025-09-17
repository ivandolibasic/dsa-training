// fscanf() - reads from a file instead of stdin

#include <stdio.h>

int main() {
    FILE *f = fopen("input.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    printf("n = %d", n);
    return 0;
}