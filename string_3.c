#include <stdio.h>
#include <math.h>

int main() {
    double num;

    printf("Enter a floating-point number: ");
    scanf("%lf", &num);

    if (num >= 0) {
        printf("Square root of %.2f: %.2f\n", num, sqrt(num));
    } else {
        printf("Error: Cannot compute square root of a negative number.\n");
    }

    printf("Rounded value: %.0f\n", round(num));

    printf("Sine of %.2f (in radians): %.2f\n", num, sin(num));

    return 0;
}
