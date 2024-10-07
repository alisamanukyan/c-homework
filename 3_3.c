#include <stdio.h>

void expand(char s1[], char s2[]) {
    int i = 0, j = 0;
    char start, end;

    while (s1[i] != '\0') {
        if (s1[i] != '-') {
            s2[j++] = s1[i]; 
        } else if (i > 0 && s1[i + 1] != '\0' && s1[i - 1] < s1[i + 1]) {
            start = s1[i - 1]; 
            end = s1[i + 1];  
            for (char c = start + 1; c < end; c++) {
                s2[j++] = c;  
            }
        }
        i++;
    }
    s2[j] = '\0'; 
}

int main() {
    char s1[100];  
    char s2[200];  

    printf("Enter a string (e.g., a-d0-3): ");
    scanf("%s", s1);  

    expand(s1, s2);  

    printf("Expanded: %s\n", s2);  
    return 0;
}
