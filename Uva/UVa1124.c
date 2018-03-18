#include <stdlib.h>
#include <stdio.h>

int main() {

    char s;

    while ((s=getchar()) != EOF) 
        putchar(s);

    return 0;
}