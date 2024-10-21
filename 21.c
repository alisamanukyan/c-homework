#include <stdio.h>

int main() {
    char alphabets[] = "abcdefghijklmnopqrstuvwxyz";
    
    char *ptr = alphabets;

    printf("All alphabets:\n");
    while (*ptr != '\0') {  
        printf("%c ", *ptr); 
        ptr++;               
    }
    
    printf("\n");
    return 0;
}
