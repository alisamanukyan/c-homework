#include <stdio.h>

void print_pyramid(int n);

int main() {
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    print_pyramid(rows);

    return 0;
}

void print_pyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        
        printf("\n");
    }
}
