//  Write a program in C to find the largest element using Dynamic Memory Allocation.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    float *el;

    printf("Input n: ");
    scanf("%d", &n);

    el = (float *)calloc(n, sizeof(float));

    if (el == NULL) {
        printf("No memory is allocated");
        exit(0);
    }

    printf("\n");

    for (i = 0; i < n; ++i) {
        printf("Number %d: ", i + 1);
        scanf("%f", el + i);
    }

    float max = *el; 
    for (i = 1; i < n; i++) {
        if (max < *(el + i)) {
            max = *(el + i);
        }
    }

    printf("The largest element is: %f\n", max);

    free(el);

    return 0;
}
