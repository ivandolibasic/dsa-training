#include <stdio.h>
#include <stdlib.h>

int read_file() {
    FILE *fptr = fopen("filename.txt", "r");
    char myString[100];
    while (fgets(myString, sizeof myString, fptr)) {
        printf("%s", myString);
    }
    fgets(myString, sizeof myString, fptr);
    fclose(fptr);
    return EXIT_SUCCESS;
}

int main() {
    read_file();
    return 0;
}