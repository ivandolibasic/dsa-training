// fputs() - prints string in file or stream, doesn't add \n

#include <stdio.h>

int main() {
    FILE *f = fopen("output.txt", "w");
    char text[] = "text";
    fputs(text, f);
    return 0;
}