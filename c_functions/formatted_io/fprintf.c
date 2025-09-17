// fprintf() - writes in a file instead of stdout

#include <stdio.h>

int main() {
    FILE *f = fopen("output.txt", "w");
    int n = 100;
    fprintf(f, "n = %d", n);
    return 0;
}