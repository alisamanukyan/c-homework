#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int n);
void find_prime_pairs(int n);

int main() {
    int number;

    printf("Enter a positive even number: ");
    scanf("%d", &number);

    if (number < 2) {
        printf("The number must be greater than or equal to 2.\n");
        return 1;
    }

    find_prime_pairs(number);

    return 0;
}


bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void find_prime_pairs(int n) {
    bool found = false;

    printf("Prime pairs that sum up to %d:\n", n);
    for (int i = 2; i <= n / 2; i++) {
        int j = n - i;
        if (is_prime(i) && is_prime(j)) {
            printf("%d + %d\n", i, j);
            found = true;
        }
    }

    if (!found) {
        printf("No prime pairs found that sum up to %d.\n", n);
    }
}
