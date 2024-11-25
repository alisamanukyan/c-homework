// Write a program in C to print all the alphabets using a pointer.
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *alph;  
    char *ptr;   

    alph = (char *)malloc(26 * sizeof(char));
    if (alph == NULL) {  
        printf("Memory allocation failed.\n");
        return 1;
    }

    ptr = alph;  

    for (int x = 0; x < 26; x++) {
        *(ptr + x) = 'A' + x;  
    }

    printf("The Alphabets are:\n");
    for (int x = 0; x < 26; x++) {
        printf("%c ", *(ptr + x));
    }
    printf("\n");

    free(alph);

    return 0;
}