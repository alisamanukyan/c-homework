#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int left, int right) {
    if (left == right) {
        printf("%s ", str); 
    } else {
        for (int i = left; i <= right; i++) {
            swap((str + left), (str + i)); 
            permute(str, left + 1, right); 
            swap((str + left), (str + i)); 
        }
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str); 

    printf("The permutations of the string are:\n");
    permute(str, 0, n - 1); 

    printf("\n"); 
    return 0;
}
