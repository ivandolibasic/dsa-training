/*
Napisati rekurzivnu funkciju koja za zadani cijeli broj vraća broj koji je dobiven tako da 
se svako pojavljivanje neparnih znamenki (pojava jedne ili više uzastopnih znamenki) u broju 
N zamjeni točno jednom znamenkom 1. Poredak parnih znamenki (uključujući 0) se ne mijenja.

Primjer ulaza:
11455132
Primjer izlaza:
1412
*/

#include <stdio.h>

//rekurzivna funkcija
long funkcija(long n) {
    if (n == 0)
        return 0;
    long ostatak = n % 10;
    long ostatak_ostatka = (n / 10) % 10;
    if (ostatak % 2 == 1) {
        while ((n % 10) % 2 == 1) {
            n /= 10;
        }
        return funkcija(n) * 10 + 1;
    }
    else {
        return funkcija(n / 10) * 10 + ostatak;
    }
}

int main(void) {
    long a;
    scanf("%ld",&a);
    printf("%ld\n", funkcija(a));
    return 0;
}