// Write a program in C to sort an array using a pointer.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a, tmp, n;

    printf("Input n: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1; 
    }

    for (int i = 0; i < n; i++) {
        printf("Element - %d: ", i + 1);
        scanf("%d", a + i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(a + i) > *(a + j)) {
                tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element - %d : %d\n", i + 1, *(a + i));
    }

    free(a);

    return 0;
}