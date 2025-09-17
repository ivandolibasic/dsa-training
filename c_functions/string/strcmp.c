// strcmp() - compares two strings based on characters' ASCII values, returns 0 if equal, <0 if str1 < str2, >0 if str1 > str2

#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "text", b[] = "text2";
    if (strcmp(a, b) == 0) printf("a = b");
    else if (strcmp(a, b) < 0) printf("a < b");
    else printf("a > b");
    return 0;
}