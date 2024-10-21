#include <stdio.h>

void addition();
void subtraction();
void multiplication();
void division();

int main() {
    int choice;
    
    do {
        printf("\nSimple Calculator Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Quit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option! Please choose a number between 1 and 5.\n");
        }
    } while (choice != 5);  

    return 0;
}

void addition() {
    double num1, num2, result;
    printf("Enter two numbers for addition: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 + num2;
    printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
}

void subtraction() {
    double num1, num2, result;
    printf("Enter two numbers for subtraction: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 - num2;
    printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
}

void multiplication() {
    double num1, num2, result;
    printf("Enter two numbers for multiplication: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 * num2;
    printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
}

void division() {
    double num1, num2, result;
    printf("Enter two numbers for division: ");
    scanf("%lf %lf", &num1, &num2);
    
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        result = num1 / num2;
        printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
    }
}
