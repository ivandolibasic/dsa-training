#include <stdio.h>

int main(void) {
    // NAPISATI PROGRAM KOJI ĆE UČITATI KARTE I IZRAČUNATI I ISPISATI BROJ BODOVA
    FILE *f = fopen("tablic.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    int points = 0;
    for (int i = 0; i < n; i++) {
        char type[3];
        int color;
        fscanf(f, "%s %d", type, &color);
        // https://www.programiz.com/c-programming/library-function/string.h/strcmp
        if (strcmp(type, "A") == 0 || strcmp(type, "J") == 0 || strcmp(type, "Q") == 0 || strcmp(type, "K") == 0)
            points += 1;
        else if (strcmp(type, "2") == 0 && color == 4)
            points +=1;
        else if (strcmp(type, "10") == 0) {
            if (color == 3)
                points += 2;
            else
                points += 1;
        }
    }
    if (n >= 27)
        points += 3;
    printf("%d", points);
    return 0;
}