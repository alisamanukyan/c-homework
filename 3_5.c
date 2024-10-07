#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    size_t i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int b) {
    int i = 0;
    int num = n; 

    do {
        int remainder = num % b;
        s[i++] = (char)((remainder < 10) ? remainder + '0' : remainder - 10 + 'A'); 
        num = num / b;
    } while (num > 0);
    
    s[i] = '\0'; 
    reverse(s);  
}

int main() {
    int n;
    char s[100];
    int base;

    printf("Enter a number: \n");
    scanf("%d", &n);
    printf("Enter the base (2-36): \n");
    scanf("%d", &base);

    itob(n, s, base);
    printf("Number %d in base %d is: %s\n", n, base, s);

    return 0;
}